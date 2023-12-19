#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QComboBox>
#include <QString>
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_toolButton_clicked();

private:
    Ui::Form *ui;
    void _connect();
    void set_ComboBox_index(QComboBox *box);
    QString convertBase(const QString &number, int sourceBase, int targetBase);
};

#endif // FORM_H
