#ifndef __PARAMS__I8237__
#define __PARAMS__I8237__

namespace X86ISA {
class I8237;
} // namespace X86ISA


#include "params/BasicPioDevice.hh"

struct I8237Params
    : public BasicPioDeviceParams
{
    X86ISA::I8237 * create();
};

#endif // __PARAMS__I8237__
