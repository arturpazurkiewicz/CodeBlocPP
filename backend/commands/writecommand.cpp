//
// Created by Artur on 02.04.2022.
//

#include "writecommand.h"

WriteCommand::WriteCommand(std::function<void(bool)> *breakFunction, Variable *variableOut) : Command(breakFunction),
                                                                                 variableOut(variableOut) {}

int WriteCommand::run(std::function<void(const std::string)> outputFunction, int currentLine) {
    outputFunction(std::to_string(variableOut->getValue()));
    return currentLine + 1;
}

bool WriteCommand::isValid(std::function<void(const std::string)> outputFunction, int currentLine, int maxLine) {
    if (variableOut == nullptr) {
        outputFunction(std::to_string(currentLine) + ": invalid variable");
        return false;
    }
    return true;
}
