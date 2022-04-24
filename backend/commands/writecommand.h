//
// Created by Artur on 02.04.2022.
//

#ifndef CODEBLOCPP_WRITECOMMAND_H
#define CODEBLOCPP_WRITECOMMAND_H


#include "backend/command.h"
#include "backend/variable.h"

class WriteCommand : public Command {
public:
    WriteCommand(std::function<void(bool)> *breakFunction, Variable *variableOut);

    Variable *variableOut;

    int run(std::function<void(const std::string)> outputFunction, int currentLine) override;

    bool isValid(std::function<void(const std::string)> outputFunction, int currentLine, int maxLine) override;
};


#endif //CODEBLOCPP_WRITECOMMAND_H
