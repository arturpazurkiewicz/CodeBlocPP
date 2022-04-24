//
// Created by Artur on 02.04.2022.
//

#include "operationcommand.h"

OperationCommand::OperationCommand(std::function<void(bool)> *breakFunction, Variable *variable1, Variable *variable2,
                                   Variable *variableOut, Operation operation) : Command(breakFunction),
                                                                                 variable1(variable1),
                                                                                 variable2(variable2),
                                                                                 variableOut(variableOut),
                                                                                 operation(operation) {}

int OperationCommand::run(std::function<void(const std::string)> outputFunction, int currentLine) {
    int oldValue = variable1->getValue();
    if (operation == DIVIDE && variable2->getValue() == 0){
        outputFunction(std::to_string(currentLine) + ": divide by 0");
        return -1;
    }

    operationOnLeft(variable1, variable2, operation);
    if (variableOut != variable1) {
        variableOut->setValue(variable1->getValue());
        variable1->setValue(oldValue);
    }
    return currentLine + 1;
}

bool OperationCommand::isValid(std::function<void(const std::string)> outputFunction, int currentLine, int maxLine) {
    if (variable1 == nullptr || variable2 == nullptr) {
        outputFunction(std::to_string(currentLine) + ": invalid values");
        return false;
    }
    return true;
}

