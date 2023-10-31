#ifndef CALCULATOR_H
#define CALCULATOR_H



#include<stack>
#include<QToolButton>


class Calculator {
public:
    Calculator();
    friend class MainWindow;
private:
    bool _equal();
    bool hasHigherPrecedence(QChar op1, QChar op2);
    void processOperator(std::stack<QChar>& operators, std::stack<double>& values);
};
Calculator::Calculator(){}
#endif // CALCULATOR_H
