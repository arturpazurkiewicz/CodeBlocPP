#ifndef CODEBLOCPP_COMPILERVALIDATOR_H
#define CODEBLOCPP_COMPILERVALIDATOR_H

#include <vector>
#include "command.h"

class CompilerValidator {
public:
    static bool isCompilerDataValid(std::function<void(const std::string)> outputFunction, std::vector<Command *> *commands);
};


#endif //CODEBLOCPP_COMPILERVALIDATOR_H
