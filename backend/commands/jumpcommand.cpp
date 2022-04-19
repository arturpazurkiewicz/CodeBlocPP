//
// Created by Artur on 02.04.2022.
//

#include "jumpcommand.h"

int JumpCommand::run(void (*outputFunction)(std::string), int currentLine) {
    return line;
}

bool JumpCommand::isValid(void (*outputFunction)(std::string), int currentLine, int maxLine) {
    if (line < 0 || line > maxLine || line == currentLine) {
        outputFunction(std::to_string(currentLine) + ": invalid jump");
        return false;
    }
    return true;
}
