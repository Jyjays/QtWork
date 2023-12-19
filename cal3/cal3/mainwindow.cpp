#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QToolButton>
#include <QTextCursor>
#include <QVBoxLayout>
#include <QDebug>
#include <QTimer>

double num;
QString operat;
QString _text;

std::stack<QChar> operators;
std::stack<double> values;


typedef exprtk::symbol_table<double> symbol_table_t;
typedef exprtk::expression<double>   expression_t;
typedef exprtk::parser<double>       parser_t;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("简易计算器");
    ui->plainTextEdit->setPlainText("");
    _text = ui->plainTextEdit->toPlainText();
    ui->plainTextEdit->setFocus();

    connectButton();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::connectButton() {
    QToolButton *numButtons[11];
    for (int i = 0; i < 11; i++) {
        QString numName = "num" + QString::number(i);
        numButtons[i] = findChild<QToolButton*>(numName);
        connect(numButtons[i], &QToolButton::clicked, this, &MainWindow::numOnClick);

    }
    connect(ui->jia, &QToolButton::clicked, this, &MainWindow::fuHao);
    connect(ui->jian, &QToolButton::clicked, this, &MainWindow::fuHao);
    connect(ui->cheng, &QToolButton::clicked, this, &MainWindow::fuHao);
    connect(ui->chu, &QToolButton::clicked, this, &MainWindow::fuHao);
    connect(ui->equal,&QToolButton::clicked,this,&MainWindow::fuHao);
    connect(ui->right,&QToolButton::clicked,this,&MainWindow::_move);
    connect(ui->left,&QToolButton::clicked,this,&MainWindow::_move);
    connect(ui->del,&QToolButton::clicked,this,&MainWindow::_delete);
    connect(ui->ac,&QToolButton::clicked,this,&MainWindow::_delete);
    connect(ui->right_kuo,&QToolButton::clicked,this,&MainWindow::fuHao);
    connect(ui->left_kuo,&QToolButton::clicked,this,&MainWindow::fuHao);
    connect(ui->sin,&QToolButton::clicked,this,&MainWindow::fuHao);
    connect(ui->cos,&QToolButton::clicked,this,&MainWindow::fuHao);
    connect(ui->pow,&QToolButton::clicked,this,&MainWindow::fuHao);
    connect(ui->sin1,&QToolButton::clicked,this,&MainWindow::fuHao);
    connect(ui->cos1,&QToolButton::clicked,this,&MainWindow::fuHao);
    connect(ui->tan1,&QToolButton::clicked,this,&MainWindow::fuHao);
}

void MainWindow::numOnClick(){
    QToolButton *numName = (QToolButton*)sender();
    ui->plainTextEdit->textCursor().insertText(numName->text());
    _text = ui->plainTextEdit->toPlainText();
}

void MainWindow::fuHao(){
    QToolButton *fuhao = (QToolButton*)sender();
    if(fuhao->text()!="="){
        QString fh = fuhao->text();
        ui->plainTextEdit->textCursor().insertText(fh);
    }
    else{
        if(_equal()){
            ui->plainTextEdit->clear();
            QString str=QString::number(num);
            ui->plainTextEdit->textCursor().insertText(str);

            _text = ui->plainTextEdit->toPlainText();
        }else{
            ui->plainTextEdit->setPlainText("error");

            QTimer::singleShot(2000, [this]() {
                ui->plainTextEdit->clear();
            });

        }

    }
}

void MainWindow::_move(){
    QToolButton *_action = (QToolButton*)sender();
    // qDebug()<<_action;
    if(_action->text()=="->"){
        //        QTextCursor cursor = ui->plainTextEdit->textCursor();
        //        cursor.movePosition(QTextCursor::Right);
        //        ui->plainTextEdit->setTextCursor(cursor);
        ui->plainTextEdit->moveCursor(QTextCursor::Right);
    }
    if(_action->text()=="<-"){
        ui->plainTextEdit->moveCursor(QTextCursor::Left);
    }
}


void MainWindow::_delete(){
    QToolButton *_action = (QToolButton*)sender();
    if(_action->text() == "DEL"){
        //        _text = ui->plainTextEdit->toPlainText();
        //        _text.chop(1);
        //        ui->plainTextEdit->setPlainText(_text);
        QTextCursor cursor = ui->plainTextEdit->textCursor();
        cursor.deletePreviousChar();
        _text = ui->plainTextEdit->toPlainText();
    }
    if(_action->text()== "AC"){
        ui->plainTextEdit->clear();
        //        while(!operators.empty()) operators.pop();
        //        while(!values.empty ()) values.pop();
        _text = "";
        num = 0;
    }

}


bool MainWindow::_equal() {
    // 获取 QPlainTextEdit 中的表达式
    QString expressionStr = ui->plainTextEdit->toPlainText();

    // 使用 ExprTk 计算表达式
    double result;
    if (evalcpp(expressionStr, num)) {
        // 将结果显示回 QPlainTextEdit
        ui->plainTextEdit->setPlainText(QString::number(num));
        return true;
    } else {
        // 表达式解析错误，返回 false
        return false;
    }
}

bool MainWindow::evalcpp(const QString &expr, double &num) {
    symbol_table_t symbolTable;
    expression_t expression;
    parser_t parser;

    // 添加可能用到的变量到符号表（根据需要修改）
    // symbolTable.add_variable("x", someValue);

    // 判断表达式中是否包含反三角函数
    bool containsInverseTrigFunctions = expr.contains("arcsin") || expr.contains("arccos") || expr.contains("arctan");

    // 添加反三角函数到符号表
    if (containsInverseTrigFunctions) {
        symbolTable.add_function("arcsin", [](double x) { return std::asin(x); });
        symbolTable.add_function("arccos", [](double x) { return std::acos(x); });
        symbolTable.add_function("arctan", [](double x) { return std::atan(x); });
    }

    // 将符号表绑定到表达式
    expression.register_symbol_table(symbolTable);

    // 尝试编译并计算表达式
    if (parser.compile(expr.toStdString(), expression)) {
        num = expression.value();

        // 如果表达式包含反三角函数，则将弧度转化为角度
        if (containsInverseTrigFunctions) {
            num = 360*num/(2*3.1415);
        }

        return true;
    } else {
        // ExprTk 解析错误
        qDebug() << "Error: Expression parsing failed.";
        return false;
    }
}
void MainWindow::on_formButton_clicked()
{
    Form *transForm = new Form;
    transForm->show();
}


