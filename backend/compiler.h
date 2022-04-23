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
             void (*outputFunction)(std::string));

    Compiler(std::vector<Command *> &commands, std::set<int> *breakpoints, Mode mode,
             void (*outputFunction)(std::string), CompilerValidator &compilerValidator);

    bool run();

    bool run(bool nextLine);

    void check(std::function<void(const std::string)> func){
        func("hej sokoły!");
    }

private:
    std::vector<Command *> commands;
    std::set<int> *breakpoints;
//    std::vector<Variable *> variables;
    const Mode mode;
    int currentLine = 0;
    bool isValid;

    void (*outputFunction)(std::string);

    bool oneStep();

    void breakFunction(bool enabled);

    CompilerValidator compilerValidator;

};

#endif // COMPILER_H
