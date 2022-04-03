#include "variable.h"

Variable::Variable(std::string variable, int startValue) : variable(variable), startValue(startValue),
                                                            value(startValue) {}

std::string Variable::getVariable() {
    return variable;
}

void Variable::setVariable(std::string variable) {
    Variable::variable = variable;
}

int Variable::getStartValue() const {
    return startValue;
}

void Variable::setStartValue(int startValue) {
    Variable::startValue = startValue;
    Variable::value = startValue;
}

int Variable::getValue() const {
    return value;
}

void Variable::setValue(int value) {
    Variable::value = value;
}



Variable Variable::operator+=(const Variable &rhs) {
    this->value += rhs.value;
    return *this;
}

Variable Variable::operator-=(const Variable &rhs) {
    this->value -= rhs.value;
    return *this;
}

Variable Variable::operator*=(const Variable &rhs) {
    this->value *= rhs.value;
    return *this;
}

Variable Variable::operator/=(const Variable &rhs) {
    this->value /= rhs.value;
    return *this;
}

bool Variable::operator==(const Variable &rhs) const {
    return value == rhs.value;
}

bool Variable::operator!=(const Variable &rhs) const {
    return !(rhs == *this);
}

bool Variable::operator<(const Variable &rhs) const {
    return value < rhs.value;
}

bool Variable::operator>(const Variable &rhs) const {
    return rhs < *this;
}

bool Variable::operator<=(const Variable &rhs) const {
    return !(rhs < *this);
}

bool Variable::operator>=(const Variable &rhs) const {
    return !(*this < rhs);
}
