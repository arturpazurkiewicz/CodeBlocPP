//
// Created by Artur on 02.04.2022.
//

#include "jumpcommand.h"


JumpCommand::JumpCommand(std::function<void(bool)> *breakFunction, int line) : Command(breakFunction),
                                                                               line(line) {}

int JumpCommand::run(std::function<void(const std::string)> outputFunction, int currentLine) {
    return line;
}

bool JumpCommand::isValid(std::function<void(const std::string)> outputFunction, int currentLine, int maxLine) {
    if (line < 0 || line > maxLine || line == currentLine) {
        outputFunction(std::to_string(currentLine) + ": invalid jump");
        return false;
    }
    return true;
}
