#ifndef __PARAMS__I8254__
#define __PARAMS__I8254__

namespace X86ISA {
class I8254;
} // namespace X86ISA

#include <cstddef>
#include "params/X86IntSourcePin.hh"

#include "params/BasicPioDevice.hh"

struct I8254Params
    : public BasicPioDeviceParams
{
    X86ISA::I8254 * create();
    X86ISA::IntSourcePin * int_pin;
};

#endif // __PARAMS__I8254__
