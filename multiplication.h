#pragma once
#include "Instruction.h"

class MUL : public Inst
{
public:
    MUL(std::string arg): Inst(Type::MUL, arg) {}

    void execute(AProgCalculator &pcalc) override;
};

