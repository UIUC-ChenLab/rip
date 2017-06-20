#ifndef __PARAMS__ArmPMU__
#define __PARAMS__ArmPMU__

namespace ArmISA {
class PMU;
} // namespace ArmISA

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/Platform.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct ArmPMUParams
    : public SimObjectParams
{
    ArmISA::PMU * create();
    int eventCounters;
    Platform * platform;
    int pmuInterrupt;
};

#endif // __PARAMS__ArmPMU__
