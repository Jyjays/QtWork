#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    undoStack = new QUndoStack(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


//打开文件
void MainWindow::on_toolButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "打开文件", ".", "Text Files (*.txt);;C/C++ Files (*.c *.cpp)");

    if (fileName.isEmpty())
    {
        ui->statusbar->showMessage("打开文件失败");
        return;
    }
    currentPath = fileName;
    //打开文件
    QFile file(fileName);
    bool ret = file.open(QIODevice::ReadOnly);
    if(!ret){
        ui->statusbar->showMessage("打开文件失败");
        return;
    }
    //读取文件内容
    QByteArray buf = file.readAll();
    QString str = QString::fromUtf8(buf);
    ui->plainTextEdit->setPlainText(str);
}

//保存文件
void MainWindow::on_toolButton_14_clicked()
{
    if (currentPath.isEmpty())
    {
        ui->statusbar->showMessage("文件路径为空，无法保存");
        return;
    }

    QFile file(currentPath);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << ui->plainTextEdit->toPlainText();
        file.close();
        ui->statusbar->showMessage("文件已保存");
    }
    else
    {
        ui->statusbar->showMessage("保存文件失败");
    }
}

//另存文件
void MainWindow::on_toolButton_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "另存文件", ".", "Text Files (*.txt);;C/C++ Files (*.c *.cpp)");
    if(fileName.isEmpty()){
        ui->statusbar->showMessage("保存失败");
        return;
    }
    QFile file(fileName);
    bool ret = file.open(QIODevice::ReadWrite | QIODevice::Truncate);
    if(!ret){
        ui->statusbar->showMessage("打开文件失败");
        return;
    }
    //写入（编码）
    QString str = ui->plainTextEdit->toPlainText();

    //把Qsting类型的str写入文件中
    //QByteArray buf = str.toUtf8();
    QByteArray buf = str.toLocal8Bit();
    file.write(buf);
    ui->statusbar->showMessage("保存成功",2000);
}

// 撤回操作
void MainWindow::on_toolButton_3_clicked()
{
    ui->plainTextEdit->undo();
}

// 恢复操作
void MainWindow::on_toolButton_6_clicked()
{

    ui->plainTextEdit->redo();
}



