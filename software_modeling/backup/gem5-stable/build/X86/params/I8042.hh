#ifndef __PARAMS__I8042__
#define __PARAMS__I8042__

namespace X86ISA {
class I8042;
} // namespace X86ISA

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/X86IntSourcePin.hh"
#include <cstddef>
#include "params/X86IntSourcePin.hh"

#include "params/BasicPioDevice.hh"

struct I8042Params
    : public BasicPioDeviceParams
{
    X86ISA::I8042 * create();
    Addr command_port;
    Addr data_port;
    X86ISA::IntSourcePin * keyboard_int_pin;
    X86ISA::IntSourcePin * mouse_int_pin;
};

#endif // __PARAMS__I8042__
