#pragma once

#include "AProgCalc.h"

class Interface
{
public:
    Interface():pc(new AProgCalculator()) {}
    void printState();
    void runCommands();

private:
    bool inputFile(std::string cmd);
    bool runDebug();
    bool runAll();
    bool runContinue();
    void printReg();
    void printMemory();

private:
    AProgCalculator *pc;
};
