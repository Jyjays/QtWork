#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "puzzleGameForm.h"
#include <QLabel>
#include <QPoint>
#include <QVector>
#include <QList>
#include <QMap>
#include <QPixmap>
#include <QMimeData>
#include <QTimer>
#include <QMessageBox>
#include <QPushButton>
#include <QComboBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //friend class puzzleGameForm;
protected:
    void dragEnterEvent(QDragEnterEvent *event) override;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;

    void startGame();
    void loadImage();
    void initializePuzzle();


    int cols;
    int rows;
    int pieceWidth;
    int pieceHeight;
    int windowWidth;
    int windowHeight;
    QPixmap puzzleImage;
    //QLabel *draggedLabel;
    QPoint offset;
    QPoint offPoint;
    QTimer* timer;
    //QMap<QPoint,QLabel*> LabelMap;

};
#endif // MAINWINDOW_H
