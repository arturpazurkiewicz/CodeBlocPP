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
    OperationCommand(std::function<void(bool)> *breakFunction, Variable *variable1, Variable *variable2, Variable *variableOut,
                     Operation operation);

    Variable *variable1;
    Variable *variable2;
    Variable *variableOut;
    Operation operation;

    int run(std::function<void(const std::string)> outputFunction, int currentLine) override;

    bool isValid(std::function<void(const std::string)> outputFunction, int currentLine, int maxLine) override;


};


template<class T>
T operationOnLeft(T l, const T r, const Operation operation) {
    switch (operation) {
        case PLUS:
            *l += *r;
            break;
        case MINUS:
            *l -= *r;
            break;
        case MULTIPLY:
            *l *= *r;
            break;
        case DIVIDE:
            *l /= *r;
            break;
    }
    return l;
}


#endif //CODEBLOCPP_OPERATIONCOMMAND_H
