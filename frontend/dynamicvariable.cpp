#include "dynamicvariable.h"


DynamicVariable::DynamicVariable(QWidget *parent) :
    QPushButton(parent)
{
    Variable++;
    variable = Variable;
    value = Value;
}

DynamicVariable::~DynamicVariable()
{

}

int DynamicVariable::getVariable()
{
    return variable;
}

int DynamicVariable::getValue()
{
    return value;
}

/* Initialize static class variable.
 * Static class variable must be initialized without fail
 * */
int DynamicVariable::Variable = 0;
int DynamicVariable::Value = 0;
