#include "AProgCalc.h"
#include "jump.h"

void JMP::execute(AProgCalculator &pcalc)
{
    //std::cout << "check" << std::endl;
    std::string address = pcalc.getSymbol(getArgument());
    char reg = address.at(3);
    //std::cout << reg << std::endl;
    unsigned first = address.find("?");
    unsigned last = address.find(".");
    int val = std::stoi(address.substr(first+2, last-first-1));
    double value{};
    if(reg == 'w')
    {
        value = pcalc.getRegW();
    }
    else if(reg == 'x')
    {
        value = pcalc.getRegX();
    }
    else if(reg == 'y')
    {
        value = pcalc.getRegY();
    }
    else if(reg == 'z')
    {
        value = pcalc.getRegZ();
    }

    if(value == 0)
    {
        pcalc.setPC(pcalc.getPC()+1);
    }
    else
    {
        pcalc.setPC(val-1);
    }
}
