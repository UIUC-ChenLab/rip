#ifndef __PARAMS__ArmInterrupts__
#define __PARAMS__ArmInterrupts__

namespace ArmISA {
class Interrupts;
} // namespace ArmISA


#include "params/SimObject.hh"

struct ArmInterruptsParams
    : public SimObjectParams
{
    ArmISA::Interrupts * create();
};

#endif // __PARAMS__ArmInterrupts__
