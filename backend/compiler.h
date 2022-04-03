#ifndef COMPILER_H
#define COMPILER_H

#include <vector>
#include <set>
#include "command.h"
#include "variable.h"

enum Mode{
    NORMAL, DEBUG
};

class Compiler {
public:
    Compiler(std::vector<Command *> &commands, std::set<int> *breakpoints, Mode mode, void (*outputFunction)(std::string));

    bool run();

    bool run(bool nextLine);

private:
    std::vector<Command *> commands;
    std::set<int> *breakpoints;
//    std::vector<Variable *> variables;
    const Mode mode;
    int currentLine = 0;
    void (*outputFunction)(std::string);
    bool oneStep();
    void breakFunction(bool enabled);
};

#endif // COMPILER_H
