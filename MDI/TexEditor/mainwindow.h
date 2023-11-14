#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Qt>
#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QByteArray>
#include <QUndoStack>
#include "texteditcommand.h"
#include <QTabWidget>
#include <QDir>
#include <QMap>
#include <QTextCharFormat>

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

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_tabWidget_currentChanged(int index);

    void on_tabWidget_tabCloseRequested(int index);

    void on_toolButton_5_clicked();

    void on_toolButton_7_clicked();

private:
    Ui::MainWindow *ui;
    QString currentPath;
    int currentPageId;
    QTextCharFormat charFormat;
    Qt::Alignment currentAlignment;

    QMap<int,QString> id_path_map;
    int pageCount;
    QPlainTextEdit* currentPlainTextEdit;
    QTabWidget* tabWidget;

    void setDefultPage();
    void getTab(QString str);
};
#endif // MAINWINDOW_H
