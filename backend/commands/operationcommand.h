//
// Created by Artur on 02.04.2022.
//

#ifndef CODEBLOCPP_OPERATIONCOMMAND_H
#define CODEBLOCPP_OPERATIONCOMMAND_H


#include "backend/command.h"
#include "backend/variable.h"

enum Operation {
    PLUS, MINUS, MULTIPLY, DIVIDE
};

class OperationCommand : public Command {
public:
    OperationCommand(void (*breakFunction)(bool), Variable *variable1, Variable *variable2, Variable *variableOut,
                     Operation operations);

    Variable *variable1;
    Variable *variable2;
    Variable *variableOut;
    Operation operation;

    int run(void (*outputFunction)(std::string), int currentLine) override;
};


template<class T>
T operationOnLeft(T l, const T r, const Operation operation) {
    switch (operation) {
        case PLUS:
            l += r;
        case MINUS:
            l -= r;
        case MULTIPLY:
            l *= r;
        case DIVIDE:
            l /= r;
    }
    return l;
}


#endif //CODEBLOCPP_OPERATIONCOMMAND_H
