#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"
#include "ui_form.h"
#include <cmath>


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
    void numOnClick();
    void fuHao();
    void _move();
    void _delete();
    void on_formButton_clicked();

private:
    Ui::MainWindow *ui;
    void connectButton();
};
#endif // MAINWINDOW_H


