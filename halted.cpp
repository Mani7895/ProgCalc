#include "AProgCalc.h"
#include "halted.h"

void HLT::execute(AProgCalculator &pcalc)
{
  pcalc.setHalt(true);
}
