#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentPageId = 0;
    pageCount = 1;
    ui->tabWidget->setTabsClosable(true);
    ui->tabWidget->removeTab(1);
    ui->tabWidget->removeTab(0);

    //setDefultPage();  //设置默认文档
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setDefultPage(){
    QString fileName = ":/Resource/intro.txt";

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

    getTab(str);
}

//打开文件
void MainWindow::on_toolButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "打开文件", ".", "Text Files (*.txt);;C/C++ Files (*.c *.cpp)");
    //qDebug()<<fileName;
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

    getTab(str);
}

void MainWindow::getTab(QString str){
    QPlainTextEdit* page = new QPlainTextEdit(this);
    page->setPlainText(str);  // 设置 QPlainTextEdit 的文本内容

    // 使用 section 函数提取文件名
    QString fileName = currentPath.section('/', -1);

    ui->tabWidget->addTab(page, fileName);
    pageCount = ui->tabWidget->count();
    qDebug()<<"pagecount:"<<pageCount;
    id_path_map.insert(pageCount-1,currentPath);
    qDebug()<<id_path_map[pageCount-1];
    ui->tabWidget->setCurrentIndex(pageCount-1);
}

//保存文件
void MainWindow::on_toolButton_14_clicked()
{

    currentPath = id_path_map[currentPageId];
    if (currentPath.isEmpty())
    {
        ui->statusbar->showMessage("文件路径为空，无法保存");
        return;
    }

    QFile file(currentPath);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << currentPlainTextEdit->toPlainText();
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
    QString str = currentPlainTextEdit->toPlainText();

    //把Qsting类型的str写入文件中
    //QByteArray buf = str.toUtf8();
    QByteArray buf = str.toLocal8Bit();
    file.write(buf);
    ui->statusbar->showMessage("保存成功",2000);
}

// 撤回操作
void MainWindow::on_toolButton_3_clicked()
{
    currentPlainTextEdit->undo();
}

// 恢复操作
void MainWindow::on_toolButton_6_clicked()
{

    currentPlainTextEdit->redo();
}

//改变字体
void MainWindow::on_fontComboBox_currentFontChanged(const QFont &f)
{
    charFormat = currentPlainTextEdit->currentCharFormat();
    QFont font = ui->fontComboBox->currentFont();
    //charFormat.setFont(font);
    charFormat.setFontFamily(font.family());
    currentPlainTextEdit->mergeCurrentCharFormat(charFormat);
//    // 获取当前选中文本的字体
//    charFormat = currentPlainTextEdit->currentCharFormat();
//    // 设置字体名称
//    charFormat.setFontFamily(f);
//    // 应用新的字符格式到选中文本
//    currentPlainTextEdit->mergeCurrentCharFormat(charFormat);
}





//切换标签页
void MainWindow::on_tabWidget_currentChanged(int index)
{

    currentPageId = index;
    QWidget* currentWidget = ui->tabWidget->currentWidget();
    qDebug()<<"pageid:"<<currentPageId;
    // 使用 qobject_cast 进行类型转换，确保是 QPlainTextEdit 类型
    currentPlainTextEdit = qobject_cast<QPlainTextEdit*>(currentWidget);
}

//关闭标签页
void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(currentPageId);
}

// 粗体
void MainWindow::on_toolButton_5_clicked()
{
    charFormat = currentPlainTextEdit->currentCharFormat();

    // 如果已经是粗体，则设置为正常粗细；否则，设置为粗体
    if (charFormat.fontWeight() == QFont::Bold) {
        charFormat.setFontWeight(QFont::Normal);
    } else {
        charFormat.setFontWeight(QFont::Bold);
    }

    // 应用字符格式
    currentPlainTextEdit->mergeCurrentCharFormat(charFormat);
}

//对齐方式
void MainWindow::on_toolButton_7_clicked()
{
    QTextCursor cursor = currentPlainTextEdit->textCursor();
    QTextBlockFormat blockFormat = cursor.blockFormat();

    currentAlignment = blockFormat.alignment();

    if(currentAlignment){
        qDebug()<<"左对齐";
        //QTextEdit *edit = new QTextEdit(this);

        blockFormat.setAlignment(Qt::AlignLeft);
    }


    cursor.setBlockFormat(blockFormat);
    currentPlainTextEdit->mergeCurrentCharFormat(cursor.charFormat());
}

