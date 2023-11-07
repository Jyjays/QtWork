#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QByteArray>
#include <QUndoStack>
#include "texteditcommand.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_toolButton_triggered(QAction *arg1);

    void on_toolButton_clicked();

    void on_toolButton_14_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_6_clicked();

private:
    Ui::MainWindow *ui;
    QString currentPath;

    QUndoStack *undoStack;


};
#endif // MAINWINDOW_H
