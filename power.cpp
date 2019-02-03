#include "AProgCalc.h"
#include "power.h"
#include <cmath>
#include <iostream>

void POW::execute(AProgCalculator &pcalc)
{

    std::string address = pcalc.getSymbol(getArgument());
    char reg = address.at(7);
    //std::cout << "Register check " << reg << std::endl;
    unsigned first = address.find("*");
    //std::cout << first << std::endl;
    unsigned last = address.find(".");
    //std::cout << last << std::endl;
    std::string check = address.substr(first+3, last-first-1);
    //std::cout << check << std::endl;
    last = check.find(".");
    check.erase(check.begin()+last);
    //std::cout << check << std::endl;
    double value{};
    double val{};
    if(check == "w")
    {
        //std::cout << "check w" << std::endl;
        val = pcalc.getRegW();
    }
    else if(check == "x")
    {
        //std::cout << "check x" << std::endl;
        val = pcalc.getRegX();
    }
    else if(check == "y")
    {
        //std::cout << "check y" << std::endl;
        val = pcalc.getRegY();
    }
    else if(check == "z")
    {
        //std::cout << "check z" << std::endl;
        val = pcalc.getRegZ();
    }
    else
    {
        //std::cout << "check val" << std::endl;
        val = std::stoi(check);
    }

    if(reg == 'w')
    {
        value = pow(pcalc.getRegW(), val);
    }
    else if(reg == 'x')
    {
        value = pow(pcalc.getRegX(), val);
    }
    else if(reg == 'y')
    {
        value = pow(pcalc.getRegY(), val);
    }
    else if(reg == 'z')
    {
        value = pow(pcalc.getRegZ(), val);
    }

    char regist = address.at(3);
    if(regist == 'w')
    {
        pcalc.setRegW(value);
    }
    else if(regist == 'x')
    {
        pcalc.setRegX(value);
    }
    else if(regist == 'y')
    {
        pcalc.setRegY(value);
    }
    else if(regist == 'z')
    {
        pcalc.setRegZ(value);
    }
    pcalc.setPC(pcalc.getPC()+1);
}

