//
// Created by Artur on 02.04.2022.
//

#include "operationcommand.h"

OperationCommand::OperationCommand(void (*breakFunction)(bool), Variable *variable1, Variable *variable2,
                                   Variable *variableOut, Operation operation) : Command(breakFunction),
                                                                                 variable1(variable1),
                                                                                 variable2(variable2),
                                                                                 variableOut(variableOut),
                                                                                 operation(operation) {}

int OperationCommand::run(void (*outputFunction)(std::string), int currentLine) {
    int oldValue = variable1->getValue();
    operationOnLeft(variable1, variable2, operation);
    if (variableOut != variable1){
        variableOut->setValue(variable1->getValue());
        variable1->setValue(oldValue);
    }
    return currentLine + 1;
}

