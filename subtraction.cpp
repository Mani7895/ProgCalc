#include "AProgCalc.h"
#include "subtraction.h"

void SUB::execute(AProgCalculator &pcalc)
{
    std::string address = pcalc.getSymbol(getArgument());
    char reg = address.at(3);
    unsigned first = address.find("-");
    unsigned last = address.find(".");
    int val = std::stoi(address.substr(first+2, last-first-1));
    int value{};
    if(reg == 'w')
    {
        value = pcalc.getRegW() - val;
    }
    else if(reg == 'x')
    {
        value = pcalc.getRegX() - val;
    }
    else if(reg == 'y')
    {
        value = pcalc.getRegY() - val;
    }
    else if(reg == 'z')
    {
        value = pcalc.getRegZ() - val;
    }

    char regist = address.at(3);
    if(reg == 'w')
    {
        pcalc.setRegW(value);
    }
    else if(reg == 'x')
    {
        pcalc.setRegX(value);
    }
    else if(reg == 'y')
    {
        pcalc.setRegY(value);
    }
    else if(reg == 'z')
    {
        pcalc.setRegZ(value);
    }
    pcalc.setPC(pcalc.getPC()+1);
}

