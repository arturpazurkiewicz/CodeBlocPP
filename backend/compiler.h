#ifndef COMPILER_H
#define COMPILER_H

#include <vector>
#include <set>
#include "command.h"
#include "variable.h"
#include "compilervalidator.h"
#include <functional>

enum Mode {
    NORMAL, DEBUG
};

class Compiler {
public:
    Compiler(std::vector<Command *> &commands, std::set<int> *breakpoints, Mode mode,
             const std::function<void(const std::string)> &outputFunction);

    Compiler(std::vector<Command *> &commands, std::set<int> *breakpoints, Mode mode,
             const std::function<void(const std::string)> &outputFunction, CompilerValidator &compilerValidator);

    bool run();

    bool run(bool nextLine);


    bool isValid() const;

    bool isEnded() const;

private:
    std::vector<Command *> commands;
    std::set<int> *breakpoints;
//    std::vector<Variable *> variables;
    const Mode mode;
    int currentLine = 0;
    bool valid;
    bool firstStep = true;
    bool ended = false;

    std::function<void(const std::string)> outputFunction;

    bool oneStep();

    bool innerRun(bool nextLine);


    void breakFunction(bool enabled);

    CompilerValidator compilerValidator;

};

#endif // COMPILER_H
