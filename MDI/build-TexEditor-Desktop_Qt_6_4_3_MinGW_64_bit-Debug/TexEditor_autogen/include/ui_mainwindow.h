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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QToolButton *toolButton_11;
    QToolButton *toolButton_7;
    QToolButton *toolButton_12;
    QToolButton *toolButton_9;
    QToolButton *toolButton_5;
    QToolButton *toolButton;
    QToolButton *toolButton_8;
    QToolButton *toolButton_2;
    QToolButton *toolButton_6;
    QToolButton *toolButton_14;
    QToolButton *toolButton_10;
    QToolButton *toolButton_3;
    QToolButton *toolButton_13;
    QFontComboBox *fontComboBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(799, 623);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 791, 51));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_11 = new QToolButton(gridLayoutWidget);
        toolButton_11->setObjectName("toolButton_11");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_11->sizePolicy().hasHeightForWidth());
        toolButton_11->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resourse/copy-alt.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_11->setIcon(icon);

        gridLayout->addWidget(toolButton_11, 0, 10, 1, 1);

        toolButton_7 = new QToolButton(gridLayoutWidget);
        toolButton_7->setObjectName("toolButton_7");
        sizePolicy.setHeightForWidth(toolButton_7->sizePolicy().hasHeightForWidth());
        toolButton_7->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Resourse/align-left.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon1);

        gridLayout->addWidget(toolButton_7, 0, 6, 1, 1);

        toolButton_12 = new QToolButton(gridLayoutWidget);
        toolButton_12->setObjectName("toolButton_12");
        sizePolicy.setHeightForWidth(toolButton_12->sizePolicy().hasHeightForWidth());
        toolButton_12->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Resourse/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_12->setIcon(icon2);

        gridLayout->addWidget(toolButton_12, 0, 12, 1, 1);

        toolButton_9 = new QToolButton(gridLayoutWidget);
        toolButton_9->setObjectName("toolButton_9");
        sizePolicy.setHeightForWidth(toolButton_9->sizePolicy().hasHeightForWidth());
        toolButton_9->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Resourse/symbol.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_9->setIcon(icon3);

        gridLayout->addWidget(toolButton_9, 0, 8, 1, 1);

        toolButton_5 = new QToolButton(gridLayoutWidget);
        toolButton_5->setObjectName("toolButton_5");
        sizePolicy.setHeightForWidth(toolButton_5->sizePolicy().hasHeightForWidth());
        toolButton_5->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Resourse/b.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon4);

        gridLayout->addWidget(toolButton_5, 0, 5, 1, 1);

        toolButton = new QToolButton(gridLayoutWidget);
        toolButton->setObjectName("toolButton");
        sizePolicy.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy);
        toolButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"}\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Resourse/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon5);

        gridLayout->addWidget(toolButton, 0, 0, 2, 1);

        toolButton_8 = new QToolButton(gridLayoutWidget);
        toolButton_8->setObjectName("toolButton_8");
        sizePolicy.setHeightForWidth(toolButton_8->sizePolicy().hasHeightForWidth());
        toolButton_8->setSizePolicy(sizePolicy);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Resourse/align-center.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_8->setIcon(icon6);

        gridLayout->addWidget(toolButton_8, 0, 7, 1, 1);

        toolButton_2 = new QToolButton(gridLayoutWidget);
        toolButton_2->setObjectName("toolButton_2");
        sizePolicy.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Resourse/document.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon7);

        gridLayout->addWidget(toolButton_2, 0, 2, 2, 1);

        toolButton_6 = new QToolButton(gridLayoutWidget);
        toolButton_6->setObjectName("toolButton_6");
        sizePolicy.setHeightForWidth(toolButton_6->sizePolicy().hasHeightForWidth());
        toolButton_6->setSizePolicy(sizePolicy);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Resourse/angle-right.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon8);

        gridLayout->addWidget(toolButton_6, 0, 4, 2, 1);

        toolButton_14 = new QToolButton(gridLayoutWidget);
        toolButton_14->setObjectName("toolButton_14");
        sizePolicy.setHeightForWidth(toolButton_14->sizePolicy().hasHeightForWidth());
        toolButton_14->setSizePolicy(sizePolicy);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Resourse/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_14->setIcon(icon9);

        gridLayout->addWidget(toolButton_14, 0, 1, 2, 1);

        toolButton_10 = new QToolButton(gridLayoutWidget);
        toolButton_10->setObjectName("toolButton_10");
        sizePolicy.setHeightForWidth(toolButton_10->sizePolicy().hasHeightForWidth());
        toolButton_10->setSizePolicy(sizePolicy);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Resourse/align-justify.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_10->setIcon(icon10);

        gridLayout->addWidget(toolButton_10, 0, 9, 1, 1);

        toolButton_3 = new QToolButton(gridLayoutWidget);
        toolButton_3->setObjectName("toolButton_3");
        sizePolicy.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Resourse/angle-left.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon11);

        gridLayout->addWidget(toolButton_3, 0, 3, 2, 1);

        toolButton_13 = new QToolButton(gridLayoutWidget);
        toolButton_13->setObjectName("toolButton_13");
        sizePolicy.setHeightForWidth(toolButton_13->sizePolicy().hasHeightForWidth());
        toolButton_13->setSizePolicy(sizePolicy);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Resourse/scissors.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_13->setIcon(icon12);

        gridLayout->addWidget(toolButton_13, 0, 11, 1, 1);

        fontComboBox = new QFontComboBox(centralwidget);
        fontComboBox->setObjectName("fontComboBox");
        fontComboBox->setGeometry(QRect(0, 50, 228, 24));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fontComboBox->sizePolicy().hasHeightForWidth());
        fontComboBox->setSizePolicy(sizePolicy1);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(6, 79, 791, 521));
        tabWidget->setDocumentMode(true);
        tab = new QWidget();
        tab->setObjectName("tab");
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 799, 21));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_11->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\244\215\345\210\266</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_11->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_7->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\267\246\345\257\271\351\275\220</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_7->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_12->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\347\262\230\350\264\264</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_12->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_9->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\217\263\345\257\271\351\275\220</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_9->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_5->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\212\240\347\262\227</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_5->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\211\223\345\274\200\346\226\207\344\273\266</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_8->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\260\264\345\271\263\345\261\205\344\270\255</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_8->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_2->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\344\277\235\345\255\230</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_6->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\201\242\345\244\215</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_6->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_14->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\344\277\235\345\255\230</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_14->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_10->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\344\270\244\347\253\257\345\257\271\351\275\220</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_10->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_3->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\222\244\351\224\200</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_3->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_13->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\211\252\345\210\207</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_13->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\346\234\254\347\274\226\350\276\221\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
