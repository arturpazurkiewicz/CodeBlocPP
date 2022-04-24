//
// Created by Artur on 19.04.2022.
//

#include "compilervalidator.h"

bool CompilerValidator::isCompilerDataValid(std::function<void(const std::string)> outputFunction, std::vector<Command *> *commands) {
    if (commands == nullptr) {
        outputFunction("commands cannot be null");
        return false;
    }

    bool valid = true;

    int maxLine = commands->size();
    for (int i = 0; i < maxLine; ++i) {
        if (!(*commands)[i]->isValid(outputFunction, i, maxLine)) {
            valid = false;
        }
    }

    return valid;
}
