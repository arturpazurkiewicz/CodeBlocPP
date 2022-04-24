#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <functional>

class Command {
public:
    explicit Command(std::function<void(bool)>  *breakFunction) : breakFunction(breakFunction) {}

    virtual int run(std::function<void(const std::string)> outputFunction, int currentLine) = 0;

//    Break function which informs gui to mark currently executed command
    std::function<void(bool)> *breakFunction;

    virtual bool isValid(std::function<void(const std::string)> outputFunction, int currentLine, int maxLine) = 0;
};

#endif // COMMAND_H
