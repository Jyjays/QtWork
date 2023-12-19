#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <cstdio>
#include <string>
#include "exprtk.hpp"

typedef exprtk::symbol_table<double> symbol_table_t;
typedef exprtk::expression<double>   expression_t;
typedef exprtk::parser<double>       parser_t;

double evalcpp(const QString &expr)
{
    expression_t expression;
    parser_t parser;
    parser.compile(expr.toStdString(), expression);

    double val = expression.value();
    return val;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // w.show();
    qDebug() << evalcpp("1+1");
    return 0;
    return a.exec();
}




