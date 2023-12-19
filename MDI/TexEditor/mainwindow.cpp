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



void MainWindow::getTab(QString str) {
    QTextEdit* page = new QTextEdit(this);
    // 使用 setHtml 函数显示HTML内容
    page->setHtml(str);

    // 使用 section 函数提取文件名
    QString fileName = currentPath.section('/', -1);

    ui->tabWidget->addTab(page, fileName);
    pageCount = ui->tabWidget->count();
    qDebug() << "pagecount:" << pageCount;
    id_path_map.insert(pageCount - 1, currentPath);
    qDebug() << id_path_map[pageCount - 1];
    ui->tabWidget->setCurrentIndex(pageCount - 1);
}


//打开文件
void MainWindow::on_toolButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "打开文件", ".", "Text Files (*.txt);;C/C++ Files (*.c *.cpp);;HTML Files (*.html)");
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
//打开文件
//void MainWindow::on_toolButton_clicked()
//{
//    QString fileName = QFileDialog::getOpenFileName(this, "打开文件", ".", "Text Files (*.txt);;C/C++ Files (*.c *.cpp);;HTML Files (*.html)");
//    //qDebug()<<fileName;
//    if (fileName.isEmpty())
//    {
//        ui->statusbar->showMessage("打开文件失败");
//        return;
//    }
//    currentPath = fileName;
//    //打开文件
//    QFile file(fileName);
//    bool ret = file.open(QIODevice::ReadOnly);
//    if(!ret){
//        ui->statusbar->showMessage("打开文件失败");
//        return;
//    }
//    //读取文件内容
//    QByteArray buf = file.readAll();
//    QString str = QString::fromUtf8(buf);

//    getTab(str);
//}

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
        out <<currentPlainTextEdit->toHtml();
        file.close();
        ui->statusbar->showMessage("文件已保存");
    }
    else
    {
        ui->statusbar->showMessage("保存文件失败");
    }
}
// 另存文件
void MainWindow::on_toolButton_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "另存文件", ".", "HTML Files (*.html);;Text Files (*.txt);;C/C++ Files (*.c *.cpp)");
    if (fileName.isEmpty())
    {
        ui->statusbar->showMessage("保存失败");
        return;
    }

    QFile file(fileName);
    bool ret = file.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!ret)
    {
        ui->statusbar->showMessage("保存文件失败");
        return;
    }

    // 使用toHtml函数获取HTML内容
    QString str = currentPlainTextEdit->toHtml();

    // 将HTML写入文件
    QTextStream out(&file);
    out << str;

    file.close();
    ui->statusbar->showMessage("保存成功", 2000);
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

//改变字号
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    charFormat = currentPlainTextEdit->currentCharFormat();
    charFormat.setFontPointSize(index);
    currentPlainTextEdit->mergeCurrentCharFormat(charFormat);
}




//切换标签页
void MainWindow::on_tabWidget_currentChanged(int index)
{

    currentPageId = index;
    QWidget* currentWidget = ui->tabWidget->currentWidget();
    qDebug()<<"pageid:"<<currentPageId;
    // 使用 qobject_cast 进行类型转换，确保是 QPlainTextEdit 类型
    currentPlainTextEdit = qobject_cast<QTextEdit*>(currentWidget);
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
    currentPlainTextEdit->setAlignment(Qt::AlignLeft);
}


void MainWindow::on_toolButton_8_clicked()
{
    currentPlainTextEdit->setAlignment(Qt::AlignCenter);
}


void MainWindow::on_toolButton_9_clicked()
{
    currentPlainTextEdit->setAlignment(Qt::AlignRight);
}


void MainWindow::on_toolButton_10_clicked()
{
    currentPlainTextEdit->setAlignment(Qt::AlignJustify);
}


void MainWindow::on_toolButton_11_clicked()
{
    currentPlainTextEdit->copy();
}


void MainWindow::on_toolButton_13_clicked()
{
    currentPlainTextEdit->cut();
}


void MainWindow::on_toolButton_12_clicked()
{
    currentPlainTextEdit->paste();
}

//斜体
void MainWindow::on_toolButton_15_clicked()
{
    charFormat = currentPlainTextEdit->currentCharFormat();
    charFormat.setFontItalic(charFormat.fontItalic()? false:true);
    // 应用字符格式
    currentPlainTextEdit->mergeCurrentCharFormat(charFormat);

}


void MainWindow::on_toolButton_16_clicked()
{
    charFormat = currentPlainTextEdit->currentCharFormat();

    charFormat.setFontUnderline(charFormat.fontUnderline()? false:true);
    // 应用字符格式
    currentPlainTextEdit->mergeCurrentCharFormat(charFormat);
}




