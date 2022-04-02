#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>

class Command
{
public:
    explicit Command(void (*breakFunction)(bool)) : breakFunction(breakFunction) {}

public:
    virtual int run(void (*outputFunction)(std::string), int currentLine) = 0;
protected:
//    Break function which informs gui to mark currently executed command
    void (*breakFunction)(bool){} ;
};

#endif // COMMAND_H
