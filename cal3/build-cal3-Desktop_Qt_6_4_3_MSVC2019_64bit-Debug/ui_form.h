/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label;
    QPlainTextEdit *shuru;
    QPlainTextEdit *shuchu;
    QComboBox *comboBox_2;
    QToolButton *toolButton;
    QLabel *label_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(400, 300);
        label_3 = new QLabel(Form);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 81, 31));
        QFont font;
        font.setItalic(true);
        font.setUnderline(false);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(Form);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(70, 120, 72, 24));
        label = new QLabel(Form);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 120, 51, 21));
        shuru = new QPlainTextEdit(Form);
        shuru->setObjectName("shuru");
        shuru->setGeometry(QRect(50, 60, 121, 31));
        shuchu = new QPlainTextEdit(Form);
        shuchu->setObjectName("shuchu");
        shuchu->setGeometry(QRect(210, 60, 141, 31));
        comboBox_2 = new QComboBox(Form);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(290, 120, 72, 24));
        toolButton = new QToolButton(Form);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(290, 210, 81, 21));
        label_2 = new QLabel(Form);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(230, 120, 51, 21));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "\350\277\233\345\210\266\350\275\254\346\215\242", nullptr));
        label->setText(QCoreApplication::translate("Form", "\345\216\237\350\277\233\345\210\266", nullptr));
        shuru->setPlainText(QString());
        toolButton->setText(QCoreApplication::translate("Form", "\350\275\254\346\215\242", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "\350\275\254\346\215\242\350\277\233\345\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
