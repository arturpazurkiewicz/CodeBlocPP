#include "compiler.h"


Compiler::Compiler(std::vector<Command *> &commands, std::set<int> *breakpoints, Mode mode,
                   std::function<void(const std::string)> outputFunction, CompilerValidator &compilerValidator) : commands(
        commands), breakpoints(breakpoints), mode(mode), outputFunction(outputFunction), compilerValidator(
        compilerValidator) {
    valid = compilerValidator.isCompilerDataValid(outputFunction, &commands);
}

Compiler::Compiler(std::vector<Command *> &commands, std::set<int> *breakpoints,
                   Mode mode, std::function<void(const std::string)> outputFunction)
        : Compiler(commands, breakpoints, mode, outputFunction, compilerValidator) {}


bool Compiler::run() {
    return run(false);
}

bool Compiler::run(bool nextLine) {
    ended = innerRun(nextLine);
    return ended;
}

bool Compiler::innerRun(bool nextLine) {
    if (!valid){
        return true;
    }
    if (nextLine) {
        return oneStep();
    } else {
        if (mode == DEBUG){
            bool result;
            do {
                result = oneStep();
            } while (!result && breakpoints->find(currentLine) == breakpoints->end());
            return result;
        } else {
            while (!oneStep());
        }
    }
    return true;
}


bool Compiler::oneStep() {
    if (currentLine >= 0 && currentLine < commands.size()) {
        breakFunction(false);
        currentLine = commands[currentLine]->run(outputFunction, currentLine);
        if (currentLine >= 0 && currentLine < commands.size()) {
            breakFunction(true);
            return false;
        }
    }
    return true;
}

void Compiler::breakFunction(bool enabled) {
    if (mode == DEBUG) {
        auto function = commands[currentLine]->breakFunction;
        if (function != nullptr) {
            (*function)(enabled);
        }
    }
}

bool Compiler::isValid() const {
    return valid;
}

bool Compiler::isEnded() const {
    return ended;
}


