#ifndef __PARAMS__I8259__
#define __PARAMS__I8259__

namespace X86ISA {
class I8259;
} // namespace X86ISA

#include <cstddef>
#include "enums/X86I8259CascadeMode.hh"
#include <cstddef>
#include "params/X86IntSourcePin.hh"
#include <cstddef>
#include "params/I8259.hh"

#include "params/BasicPioDevice.hh"

#include "enums/X86I8259CascadeMode.hh"

struct I8259Params
    : public BasicPioDeviceParams
{
    X86ISA::I8259 * create();
    Enums::X86I8259CascadeMode mode;
    X86ISA::IntSourcePin * output;
    X86ISA::I8259 * slave;
};

#endif // __PARAMS__I8259__
