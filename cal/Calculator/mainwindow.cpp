#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "calculator.h"
#include <QString>
#include <stack>
#include <QToolButton>
#include <QTextCursor>
#include <QVBoxLayout>
#include <QDebug>
#include <QTimer>

QString num;
QString operat;
QString _text;
Calculator calculator;
std::stack<QChar> operators;
std::stack<double> values;
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
        if(calculator._equal()){
            ui->plainTextEdit->clear();
            ui->plainTextEdit->textCursor().insertText(num);

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
        num = "";
    }

}

bool Calculator::_equal() {


    bool isNegative = false;

    for (int i = 0; i < _text.length(); i++) {
        if (_text[i].isDigit() || (_text[i] == '.' && i > 0 && _text[i - 1].isDigit())) {
            QString number;
            if (isNegative) {
                number += "-";
                isNegative = false; // 重置标志
            }
            while (i < _text.length() && (_text[i].isDigit() || _text[i] == '.')) {
                number += _text[i];
                i++;
            }
            values.push(number.toDouble());
            i--;
        } else if (_text[i] == '(') {
            operators.push(_text[i]);
        } else if (_text[i] == '-') {
            // 检查前一个字符是否是左括号，表示负数
            if (i == 0 || _text[i - 1] == '(') {
                isNegative = true;
            } else {
                while (!operators.empty() && operators.top() != '(' && hasHigherPrecedence(operators.top(), _text[i])) {
                    processOperator(operators, values);
                }
                operators.push(_text[i]);
            }
        } else if (_text[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                processOperator(operators, values);
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop();  // 弹出左括号
            } else {
                return false;
            }
        } else if (_text[i] == '+' || _text[i] == '*' || _text[i] == '/') {
            while (!operators.empty() && hasHigherPrecedence(operators.top(), _text[i])) {
                processOperator(operators, values);
            }
            operators.push(_text[i]);
        }
    }


    while (!operators.empty()) {
        processOperator(operators, values);
    }


    if (!values.empty()) {
        double result = values.top();
        num = QString::number(result);
        qDebug() << "Result: " << result;
        return true;

    }

}
bool Calculator::hasHigherPrecedence(QChar op1, QChar op2) {
    return (op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-');
}

void Calculator::processOperator(std::stack<QChar>& operators, std::stack<double>& values) {
    QChar Op = operators.top();
    char op = Op.toLatin1();
    operators.pop();
    if (values.size() < 2) {
        // Handle error, not enough operands for operator
        return;
    }
    double operand2 = values.top();
    values.pop();
    double operand1 = values.top();
    values.pop();

    double result;
    switch (op) {
    case '+':
        result = operand1 + operand2;
        break;
    case '-':
        result = operand1 - operand2;
        break;
    case '*':
        result = operand1 * operand2;
        break;
    case '/':
        if (operand2 == 0) {
            // Handle division by zero error
            return;
        }
        result = operand1 / operand2;
        break;
    default:
        // Handle invalid operator error
        return;
    }
    values.push(result);
}

void MainWindow::on_formButton_clicked()
{
    Form *transForm = new Form;
    transForm->show();
}

