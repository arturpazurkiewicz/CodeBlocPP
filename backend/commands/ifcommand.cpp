//
// Created by Artur on 02.04.2022.
//

#include "ifcommand.h"

IfCommand::IfCommand(void (*breakFunction)(bool), Variable *variable1, Variable *variable2, int jumpTrue, int jumpFalse,
                     Comparator operation) : Command(breakFunction), variable1(variable1), variable2(variable2),
                                             jumpTrue(jumpTrue), jumpFalse(jumpFalse), operation(operation) {}

int IfCommand::run(void (*outputFunction)(std::string), int currentLine) {
    if (compare(variable1, variable2, operation)) {
        return jumpTrue;
    }
    return jumpFalse;
}

bool IfCommand::isValid(void (*outputFunction)(std::string), int currentLine, int maxLine) {
    bool valid = true;
    if (variable1 == nullptr || variable2 == nullptr) {
        outputFunction(std::to_string(currentLine) + ": invalid values");
        valid = false;
    }
    if (jumpTrue < 0 || jumpTrue > maxLine || jumpTrue == currentLine) {
        outputFunction(std::to_string(currentLine) + ": invalid true jump");
        valid = false;
    }
    if (jumpFalse < 0 || jumpFalse > maxLine || jumpFalse == currentLine) {
        outputFunction(std::to_string(currentLine) + ": invalid false jump");
        valid = false;
    }
    return valid;
}

