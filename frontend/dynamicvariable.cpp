#include "dynamicvariable.h"


DynamicVariable::DynamicVariable(QWidget *parent) :
    QPushButton(parent)
{
    VariableCounter++;
    variableCounter = VariableCounter;
    myVariable->setVariable(std::to_string(VariableCounter));
    myVariable->setStartValue(value);
}

DynamicVariable::~DynamicVariable()
{

}

Variable* DynamicVariable::getMyVariable(){
    return myVariable;
}

int DynamicVariable::VariableCounter = 0;
