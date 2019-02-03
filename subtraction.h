#pragma once
#include "Instruction.h"

class SUB : public Inst
{
public:
    SUB(std::string arg): Inst(Type::SUB, arg) {}

    void execute(AProgCalculator &pcalc) override;
};
