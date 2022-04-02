#ifndef DYNAMICVARIABLE_H
#define DYNAMICVARIABLE_H

#include <QPushButton>

class DynamicVariable: public QPushButton
{
     Q_OBJECT
public:
    explicit DynamicVariable(QWidget *parent = nullptr);
       ~DynamicVariable();
       static int Variable;
       static int Value;// A static variable counter buttons rooms
       int getVariable();
       int getValue();

public slots:

private:
    int variable = 0;
    int value = 0;// Local variable number of the button
};


#endif // DYNAMICVARIABLE_H
