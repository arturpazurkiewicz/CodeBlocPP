//
// Created by Artur on 02.04.2022.
//

#ifndef CODEBLOCPP_IFCOMMAND_H
#define CODEBLOCPP_IFCOMMAND_H


#include "backend/command.h"
#include "backend/variable.h"

enum Comparator {
    NEQ, EQ, LT, GT, LE, GE
};

template<class T>
bool compare(const T l, const T r, const Comparator comparator) {
    bool result;
    switch (comparator) {
        case NEQ:
            return *l != *r;
        case EQ:
            return *l == *r;
        case LT:
            return *l > *r;
        case GT:
            return *l < *r;
        case LE:
            return *l >= *r;
        case GE:
            return *l <= *r;
    }
    return false;
}

class IfCommand : public Command {
public:
    IfCommand(void (*breakFunction)(bool), Variable *variable1, Variable *variable2, int jumpTrue, int jumpFalse,
              Comparator operation);

    Variable *variable1;
    Variable *variable2;
    int jumpTrue;
    int jumpFalse;
    Comparator operation;

    int run(void (*outputFunction)(std::string), int currentLine) override;
};


#endif //CODEBLOCPP_IFCOMMAND_H
