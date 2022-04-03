//
// Created by Artur on 02.04.2022.
//

#include "ifcommand.h"

IfCommand::IfCommand(void (*breakFunction)(bool), Variable *variable1, Variable *variable2, int jumpTrue, int jumpFalse,
                     Comparator operation) : Command(breakFunction), variable1(variable1), variable2(variable2),
                                             jumpTrue(jumpTrue), jumpFalse(jumpFalse), operation(operation) {}

int IfCommand::run(void (*outputFunction)(std::string), int currentLine) {
    if (compare(*variable1, *variable2, operation)) {
        return jumpTrue;
    }
    return jumpFalse;
}

