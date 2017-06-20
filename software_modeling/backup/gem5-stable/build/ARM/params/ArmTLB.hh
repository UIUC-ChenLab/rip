#ifndef __PARAMS__ArmTLB__
#define __PARAMS__ArmTLB__

namespace ArmISA {
class TLB;
} // namespace ArmISA

#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/ArmTableWalker.hh"

#include "params/SimObject.hh"

struct ArmTLBParams
    : public SimObjectParams
{
    ArmISA::TLB * create();
    bool is_stage2;
    int size;
    ArmISA::TableWalker * walker;
};

#endif // __PARAMS__ArmTLB__
