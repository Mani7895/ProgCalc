#include "AProgCalc.h"
#include "equal.h"
#include <iostream>

void EQU::execute(AProgCalculator &pcalc)
{
    //std::cout << "check" << std::endl;
    std::string address = pcalc.getSymbol(getArgument());
    char reg = address.at(3);
    //std::cout << reg << std::endl;
    unsigned first = address.find("=");
    unsigned last = address.find(".");
    double val = std::stoi(address.substr(first+2, last-first-1));
    //std::cout << first+2 << std::endl;
    //std::cout << last-first-1 << std::endl;
    //double val = double(value);
    //std::cout << val << std::endl;
    if(reg == 'w')
    {
        pcalc.setRegW(val);
    }
    else if(reg == 'x')
    {
        pcalc.setRegX(val);
    }
    else if(reg == 'y')
    {
        pcalc.setRegY(val);
    }
    else if(reg == 'z')
    {
        pcalc.setRegZ(val);
    }

    pcalc.setPC(pcalc.getPC()+1);
   // const std::string data = pcalc.getMemData(address)->getArgument();
   // std::cout << data << "check" << std::endl;
}

