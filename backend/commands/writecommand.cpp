//
// Created by Artur on 02.04.2022.
//

#include "writecommand.h"

WriteCommand::WriteCommand(void (*breakFunction)(bool), Variable *variableOut) : Command(breakFunction),
                                                                                 variableOut(variableOut) {}

int WriteCommand::run(void (*outputFunction)(std::string), int currentLine) {
    outputFunction(std::to_string(variableOut->getValue()));
    return currentLine + 1;
}