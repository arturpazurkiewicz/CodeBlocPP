//
// Created by Artur on 02.04.2022.
//

#ifndef CODEBLOCPP_JUMPCOMMAND_H
#define CODEBLOCPP_JUMPCOMMAND_H


#include "backend/command.h"

class JumpCommand : public Command {
public:
    JumpCommand(std::function<void(bool)> *breakFunction, int line);

    int line;

    int run(std::function<void(const std::string)> outputFunction, int currentLine) override;

    bool isValid(std::function<void(const std::string)> outputFunction, int currentLine, int maxLine) override;
};


#endif //CODEBLOCPP_JUMPCOMMAND_H
