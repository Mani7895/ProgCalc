#pragma once
#include "Instruction.h"

class HLT : public Inst
{
public:
    HLT(): Inst(Type::HLT) {}

    void execute(AProgCalculator &pcalc) override;
};

