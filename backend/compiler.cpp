#include "compiler.h"


Compiler::Compiler(std::vector<Command *> &commands, std::set<int> *breakpoints,
                   Mode mode, void (*outputFunction)(std::string))
        : commands(commands), breakpoints(breakpoints), mode(mode),
          outputFunction(outputFunction) {}

bool Compiler::run() {
    if (mode == DEBUG) {

    } else {
        while (!oneStep());
    }

    return true;
}

bool Compiler::run(bool nextLine) {
    if (nextLine) {
        return oneStep();
    } else {
        return run();
    }
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
            function(enabled);
        }
    }
}

