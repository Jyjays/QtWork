#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rows = 2;
    cols = 2;
    puzzleImage.load(":/Resource/images/picture1.jpg");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    startGame();
}
void MainWindow::on_pushButton_2_clicked()
{
    loadImage();
}
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QComboBox *senderComboBox = qobject_cast<QComboBox *>(sender());

    if (senderComboBox)
    {
        QString currentValue = senderComboBox->currentText();
        qDebug() << "Selected value: " << currentValue;
        rows = currentValue.toInt();
    }
}
void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    QComboBox *senderComboBox = qobject_cast<QComboBox *>(sender());

    if (senderComboBox)
    {
        QString currentValue = senderComboBox->currentText();
        qDebug() << "Selected value: " << currentValue;
        cols = currentValue.toInt();
    }
}

void MainWindow::startGame(){
    qDebug() << cols << " " << rows;
    puzzleGameForm *gameForm = new puzzleGameForm(nullptr); // 将父窗口设置为nullptr
    gameForm->_init(cols, rows, puzzleImage);
    gameForm->setWindowFlag(Qt::Window); // 设置为顶层窗口
    gameForm->show();
}

void MainWindow::loadImage() {
    QString fileName = QFileDialog::getOpenFileName(this, "选择图片", "", "Images (*.png *.jpg *.jpeg *.bmp *.gif)");

    if (!fileName.isEmpty()) {
        // 用户选择了图片文件
        QFile file(fileName);

        if (file.open(QIODevice::ReadOnly)) {
            QByteArray imageData = file.readAll();
            file.close();

            // 将图像数据加载到 puzzleImage
            bool success = puzzleImage.loadFromData(imageData);
            qDebug()<<puzzleImage.width();
            if (success) {
                QMessageBox::information(this, "成功", "图片更新成功!");
            } else if(!success){
                // 图片加载失败
                QMessageBox::critical(this, "错误", "无法加载所选图片。");
            } else if(puzzleImage.width()>1000||puzzleImage.height()>1000){
                QMessageBox::critical(this, "错误", "所选图片尺寸过大。");
            }
        } else {
            // 无法打开文件
            QMessageBox::critical(this, "错误", "无法打开所选图片文件。");
        }
    }
}


void MainWindow::dragEnterEvent(QDragEnterEvent *event){

}





