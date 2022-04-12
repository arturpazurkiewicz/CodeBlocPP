#ifndef DYNAMICVARIABLE_H
#define DYNAMICVARIABLE_H

#include <QPushButton>
#include "./backend/variable.h"
#include <QLocale>

class DynamicVariable: public QPushButton
{
     Q_OBJECT
public:
    explicit DynamicVariable(QWidget *parent = nullptr);
       ~DynamicVariable();
       static int VariableCounter;
       Variable* getMyVariable();

public slots:

private:
    int value = 0;
    int variableCounter = 0;
    Variable* myVariable = new Variable("", 0);
};


#endif // DYNAMICVARIABLE_H
