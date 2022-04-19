#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

class Command {
public:
    explicit Command(void (*breakFunction)(bool)) : breakFunction(breakFunction) {}

    virtual int run(void (*outputFunction)(std::string), int currentLine) = 0;

//    Break function which informs gui to mark currently executed command
    void (*breakFunction)(bool){};

    virtual bool isValid(void (*outputFunction)(std::string), int currentLine, int maxLine) = 0;
};

#endif // COMMAND_H
