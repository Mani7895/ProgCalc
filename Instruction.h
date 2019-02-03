#pragma once
#include <string>
#include <iostream>

class AProgCalculator;

class Inst
{
public:
    enum class Type
    {
        NONE,
        ADD,
        SUB,
        MUL,
        POW,
        DIV,
        EQU,
        JMP,
        HLT
    };

    Inst(Type t, std::string arg = ""): type(t), argument(arg){}

    Type getType()      const{return type;}

    std::string getArgument()    const{return argument;}

    void setType(const Type t)      {type = t;}

    void setArgument(const std::string arg)  {argument = arg;}

    std::string toString() const
    {
        std::string command = "";
        switch(getType())
        {
            case Type::NONE: return getArgument();
            case Type::ADD: command = ""; break;
            case Type::SUB: command = ""; break;
            case Type::MUL: command = ""; break;
            case Type::POW: command = ""; break;
            case Type::DIV: command = ""; break;
            case Type::EQU: command = ""; break;
            case Type::JMP: command = ""; break;
            case Type::HLT: command = ""; break;
            default: break;
        }
        return(getArgument());
    }

    virtual void execute(AProgCalculator &pcalc) = 0;

private:
    Type type;
    std::string argument;
};
