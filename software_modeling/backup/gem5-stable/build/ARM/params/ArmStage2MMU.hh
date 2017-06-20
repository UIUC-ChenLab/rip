#ifndef __PARAMS__ArmStage2MMU__
#define __PARAMS__ArmStage2MMU__

namespace ArmISA {
class Stage2MMU;
} // namespace ArmISA

#include <cstddef>
#include "params/ArmTLB.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include "params/ArmTLB.hh"

#include "params/SimObject.hh"

struct ArmStage2MMUParams
    : public SimObjectParams
{
    ArmISA::Stage2MMU * create();
    ArmISA::TLB * stage2_tlb;
    System * sys;
    ArmISA::TLB * tlb;
};

#endif // __PARAMS__ArmStage2MMU__
