#pragma once
#include "Instruction.h"

class EQU : public Inst
{
public:
    EQU(std::string arg): Inst(Type::EQU, arg) {}

    void execute(AProgCalculator &pcalc) override;
};

