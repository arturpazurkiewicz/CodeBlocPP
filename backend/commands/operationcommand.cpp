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
    variableOut->setValue(variable1->getValue());
    operationOnLeft(variableOut, variable2, operation);
    return currentLine + 1;
}

