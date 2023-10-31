/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QToolButton *num0;
    QToolButton *equal;
    QToolButton *num3;
    QToolButton *num6;
    QToolButton *num9;
    QToolButton *num8;
    QToolButton *num7;
    QToolButton *num4;
    QToolButton *num5;
    QToolButton *num2;
    QToolButton *num1;
    QToolButton *num10;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QToolButton *jia;
    QToolButton *jian;
    QToolButton *cheng;
    QToolButton *chu;
    QPlainTextEdit *plainTextEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *right;
    QToolButton *left;
    QToolButton *del;
    QToolButton *ac;
    QPushButton *formButton;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(380, 450);
        MainWindow->setMinimumSize(QSize(380, 450));
        MainWindow->setMaximumSize(QSize(380, 450));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 150, 264, 254));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        num0 = new QToolButton(gridLayoutWidget);
        num0->setObjectName("num0");
        num0->setMinimumSize(QSize(50, 40));
        num0->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(num0, 4, 1, 1, 1);

        equal = new QToolButton(gridLayoutWidget);
        equal->setObjectName("equal");
        equal->setMinimumSize(QSize(50, 40));
        equal->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(equal, 4, 2, 1, 1);

        num3 = new QToolButton(gridLayoutWidget);
        num3->setObjectName("num3");
        num3->setMinimumSize(QSize(50, 40));
        num3->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(num3, 0, 2, 1, 1);

        num6 = new QToolButton(gridLayoutWidget);
        num6->setObjectName("num6");
        num6->setMinimumSize(QSize(50, 40));
        num6->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(num6, 1, 2, 1, 1);

        num9 = new QToolButton(gridLayoutWidget);
        num9->setObjectName("num9");
        num9->setMinimumSize(QSize(50, 40));
        num9->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(num9, 2, 2, 1, 1);

        num8 = new QToolButton(gridLayoutWidget);
        num8->setObjectName("num8");
        num8->setMinimumSize(QSize(50, 40));
        num8->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(num8, 2, 1, 1, 1);

        num7 = new QToolButton(gridLayoutWidget);
        num7->setObjectName("num7");
        num7->setMinimumSize(QSize(50, 40));
        num7->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(num7, 2, 0, 1, 1);

        num4 = new QToolButton(gridLayoutWidget);
        num4->setObjectName("num4");
        num4->setMinimumSize(QSize(50, 40));
        num4->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(num4, 1, 0, 1, 1);

        num5 = new QToolButton(gridLayoutWidget);
        num5->setObjectName("num5");
        num5->setMinimumSize(QSize(50, 40));
        num5->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(num5, 1, 1, 1, 1);

        num2 = new QToolButton(gridLayoutWidget);
        num2->setObjectName("num2");
        num2->setMinimumSize(QSize(50, 40));
        num2->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(num2, 0, 1, 1, 1);

        num1 = new QToolButton(gridLayoutWidget);
        num1->setObjectName("num1");
        num1->setMinimumSize(QSize(50, 40));
        num1->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(num1, 0, 0, 1, 1);

        num10 = new QToolButton(gridLayoutWidget);
        num10->setObjectName("num10");
        num10->setMinimumSize(QSize(50, 40));
        num10->setMaximumSize(QSize(80, 50));

        gridLayout->addWidget(num10, 4, 0, 1, 1);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(280, 160, 91, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        jia = new QToolButton(verticalLayoutWidget);
        jia->setObjectName("jia");
        jia->setMaximumSize(QSize(90, 40));

        verticalLayout->addWidget(jia);

        jian = new QToolButton(verticalLayoutWidget);
        jian->setObjectName("jian");
        jian->setMaximumSize(QSize(90, 40));

        verticalLayout->addWidget(jian);

        cheng = new QToolButton(verticalLayoutWidget);
        cheng->setObjectName("cheng");
        cheng->setMaximumSize(QSize(90, 40));

        verticalLayout->addWidget(cheng);

        chu = new QToolButton(verticalLayoutWidget);
        chu->setObjectName("chu");
        chu->setMaximumSize(QSize(90, 40));

        verticalLayout->addWidget(chu);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(20, 10, 271, 51));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(9, 99, 361, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        right = new QToolButton(horizontalLayoutWidget);
        right->setObjectName("right");
        right->setMaximumSize(QSize(90, 40));

        horizontalLayout->addWidget(right);

        left = new QToolButton(horizontalLayoutWidget);
        left->setObjectName("left");
        left->setMaximumSize(QSize(90, 40));

        horizontalLayout->addWidget(left);

        del = new QToolButton(horizontalLayoutWidget);
        del->setObjectName("del");
        del->setMaximumSize(QSize(90, 40));

        horizontalLayout->addWidget(del);

        ac = new QToolButton(horizontalLayoutWidget);
        ac->setObjectName("ac");
        ac->setMaximumSize(QSize(90, 40));

        horizontalLayout->addWidget(ac);

        formButton = new QPushButton(centralwidget);
        formButton->setObjectName("formButton");
        formButton->setGeometry(QRect(290, 70, 80, 24));
        formButton->setAutoRepeat(false);
        formButton->setAutoExclusive(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 380, 21));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        num0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        num3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        num6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        num9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        num8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        num7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        num4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        num5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        num2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        num1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        num10->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        jia->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        jian->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        cheng->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        chu->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        right->setText(QCoreApplication::translate("MainWindow", "->", nullptr));
        left->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        del->setText(QCoreApplication::translate("MainWindow", "DEL", nullptr));
        ac->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        formButton->setText(QCoreApplication::translate("MainWindow", "\350\277\233\345\210\266\350\275\254\346\215\242", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\347\256\200\346\230\223\350\256\241\347\256\227\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
