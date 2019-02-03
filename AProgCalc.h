#pragma once

#include <vector>
#include <unordered_map>

class Inst;

class AProgCalculator
{
public:
    AProgCalculator(): regX(0.0), regY(0.0), regW(0.0), regZ(0.0), pc(0) {}

    double getRegX()   const{return regX;}
    double getRegY()   const{return regY;}
    double getRegW()   const{return regW;}
    double getRegZ()   const{return regZ;}
    int getPC()        const{return pc;}
    bool isHalted()    const{return halt;}

    void setRegX(const double value)    {regX = value;}
    void setRegY(const double value)    {regY = value;}
    void setRegW(const double value)    {regW = value;}
    void setRegZ(const double value)    {regZ = value;}
    void setPC(const int value)         {pc = value;}
    void setHalt(const bool value)      {halt = value;}

    Inst* getMemData(const int address) const;
    std::string getSymbol(const std::string symbol) const;
    void addMemData(std::string data);
    void addSymbol(const std::string symbol, const int address);
    void reset();

private:
    double regX;
    double regY;
    double regW;
    double regZ;
    int pc;
    bool halt;
    std::vector<Inst*> memory;
    std::unordered_map<std::string, int> symTable;
};
