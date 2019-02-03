#pragma once
#include "Instruction.h"

class ADD : public Inst
{
public:
    ADD(std::string arg): Inst(Type::ADD,arg) {}

    void execute(AProgCalculator &pcalc) override;
};
