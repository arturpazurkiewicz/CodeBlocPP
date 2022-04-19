//
// Created by Artur on 02.04.2022.
//

#ifndef CODEBLOCPP_WRITECOMMAND_H
#define CODEBLOCPP_WRITECOMMAND_H


#include "backend/command.h"
#include "backend/variable.h"

class WriteCommand : public Command {
public:
    WriteCommand(void (*breakFunction)(bool), Variable *variableOut);

    Variable *variableOut;

    int run(void (*outputFunction)(std::string), int currentLine) override;

    bool isValid(void (*outputFunction)(std::string), int currentLine, int maxLine) override;
};


#endif //CODEBLOCPP_WRITECOMMAND_H
