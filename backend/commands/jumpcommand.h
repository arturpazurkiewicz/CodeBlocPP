//
// Created by Artur on 02.04.2022.
//

#ifndef CODEBLOCPP_JUMPCOMMAND_H
#define CODEBLOCPP_JUMPCOMMAND_H


#include "backend/command.h"

class JumpCommand : public Command {
public:
    JumpCommand(void (*breakFunction)(bool), int line) : Command(breakFunction),
                                                         line(line) {}

    int line;

    int run(void (*outputFunction)(std::string), int currentLine) override;

};


#endif //CODEBLOCPP_JUMPCOMMAND_H
