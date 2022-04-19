#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>


class Variable {
public:
    Variable(std::string variable, int startValue);

    std::string getVariable();

    void setVariable(std::string variable);

    int getStartValue() const;

    void setStartValue(int startValue);

    int getValue() const;

    void setValue(int value);

    bool operator==(const Variable &rhs) const;

    bool operator!=(const Variable &rhs) const;

    bool operator<(const Variable &rhs) const;

    bool operator>(const Variable &rhs) const;

    bool operator<=(const Variable &rhs) const;

    bool operator>=(const Variable &rhs) const;

    Variable operator+=(const Variable &rhs);

    Variable operator-=(const Variable &rhs);

    Variable operator*=(const Variable &rhs);

    Variable operator/=(const Variable &rhs);

private:
    std::string variable;
    int startValue;
    int value;
};

#endif // VARIABLE_H
