#pragma once
#include "Instruction.h"

class POW : public Inst
{
public:
    POW(std::string arg): Inst(Type::POW, arg) {}

    void execute(AProgCalculator &pcalc) override;
};

