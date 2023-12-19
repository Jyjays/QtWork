#include "form.h"
#include "ui_form.h"
#include <QDebug>
#include <QString>

int _sourceBase;
int _targetBase;
QString _text1 ;
QString _text2 ;

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->shuru->setPlaceholderText("请输入");
    ui->shuchu->setPlaceholderText("输出结果");
    QComboBox *box1 = ui->comboBox;
    QComboBox *box2 = ui->comboBox_2;
    Form::set_ComboBox_index(box1);
    Form::set_ComboBox_index(box2);
    Form::_connect();
    _text1 = ui->shuru->toPlainText();
    _text2 = ui->shuchu->toPlainText();
}

Form::~Form()
{
    delete ui;
}
void Form::_connect(){
    //connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(on_comboBox_activated(int)));
}
void Form::set_ComboBox_index(QComboBox *box) {
    QStringList items;
    items << "2" << "8" << "10" << "16";
    box->addItems(items);
}

void Form::on_comboBox_activated(int index)
{
    // 获取用户选择的数字
    QString selectedContent = qobject_cast<QComboBox*>(sender())->itemText(index);
    bool conversionOk;

    _sourceBase = selectedContent.toInt(&conversionOk);
    qDebug() << "Selected Content1: " << _sourceBase;
    //return selectedContent.toInt(&conversionOk);
}


void Form::on_comboBox_2_activated(int index)
{
    QString selectedContent = qobject_cast<QComboBox*>(sender())->itemText(index);
    bool conversionOk;
    _targetBase = selectedContent.toInt(&conversionOk);
    qDebug() << "Selected Content2: " << _targetBase;
    //return selectedContent.toInt(&conversionOk);
}


void Form::on_toolButton_clicked()
{
    _text1 = ui->shuru->toPlainText();
    _text2 = Form::convertBase(_text1,_sourceBase,_targetBase);
    ui->shuchu->clear();
    ui->shuchu->setPlainText(_text2);
}

QString Form::convertBase(const QString &number, int sourceBase, int targetBase) {
    // 将输入的字符串解析为整数，使用源进制
    bool ok;
    int decimalNumber = number.toInt(&ok, sourceBase);

    if (!ok) {
        return "Invalid input";
    }

    // 将整数转换为目标进制的字符串
    QString result = QString::number(decimalNumber, targetBase).toUpper();

    return result;
}
