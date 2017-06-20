#ifndef __PARAMS__Cmos__
#define __PARAMS__Cmos__

namespace X86ISA {
class Cmos;
} // namespace X86ISA

#include <cstddef>
#include "params/X86IntSourcePin.hh"
#include <cstddef>
#include <time.h>

#include "params/BasicPioDevice.hh"

struct CmosParams
    : public BasicPioDeviceParams
{
    X86ISA::Cmos * create();
    X86ISA::IntSourcePin * int_pin;
    tm time;
};

#endif // __PARAMS__Cmos__
