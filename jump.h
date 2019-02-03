#pragma once
#include "Instruction.h"

class JMP : public Inst
{
public:
    JMP(std::string arg): Inst(Type::JMP, arg) {}

    void execute(AProgCalculator &pcalc) override;
};


