#ifndef CODEBLOCPP_COMPILERVALIDATOR_H
#define CODEBLOCPP_COMPILERVALIDATOR_H

#include <vector>
#include "command.h"

class CompilerValidator {
public:
    static bool isCompilerDataValid(void (*outputFunction)(std::string), std::vector<Command *> *commands);
};


#endif //CODEBLOCPP_COMPILERVALIDATOR_H
