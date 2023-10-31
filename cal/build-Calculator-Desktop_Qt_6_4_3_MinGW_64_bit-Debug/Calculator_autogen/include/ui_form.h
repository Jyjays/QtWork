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
    QPlainTextEdit *shuru;
    QPlainTextEdit *shuchu;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QToolButton *toolButton;
    QLabel *label_3;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(400, 257);
        shuru = new QPlainTextEdit(Form);
        shuru->setObjectName("shuru");
        shuru->setGeometry(QRect(40, 50, 121, 31));
        shuchu = new QPlainTextEdit(Form);
        shuchu->setObjectName("shuchu");
        shuchu->setGeometry(QRect(200, 50, 141, 31));
        comboBox = new QComboBox(Form);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(60, 110, 72, 24));
        label = new QLabel(Form);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 110, 51, 21));
        label_2 = new QLabel(Form);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 110, 51, 21));
        comboBox_2 = new QComboBox(Form);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(280, 110, 72, 24));
        toolButton = new QToolButton(Form);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(280, 200, 81, 21));
        label_3 = new QLabel(Form);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 0, 81, 31));
        QFont font;
        font.setItalic(true);
        font.setUnderline(false);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        shuru->setPlainText(QString());
        label->setText(QCoreApplication::translate("Form", "\345\216\237\350\277\233\345\210\266", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "\350\275\254\346\215\242\350\277\233\345\210\266", nullptr));
        toolButton->setText(QCoreApplication::translate("Form", "\350\275\254\346\215\242", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "\350\277\233\345\210\266\350\275\254\346\215\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
