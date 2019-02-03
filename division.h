#pragma once
#include "Instruction.h"

class DIV : public Inst
{
public:
    DIV(std::string arg): Inst(Type::DIV, arg) {}

    void execute(AProgCalculator &pcalc) override;
};

