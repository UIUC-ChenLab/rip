#ifndef __PARAMS__PcSpeaker__
#define __PARAMS__PcSpeaker__

namespace X86ISA {
class Speaker;
} // namespace X86ISA

#include <cstddef>
#include "params/I8254.hh"

#include "params/BasicPioDevice.hh"

struct PcSpeakerParams
    : public BasicPioDeviceParams
{
    X86ISA::Speaker * create();
    X86ISA::I8254 * i8254;
};

#endif // __PARAMS__PcSpeaker__
