#ifndef __PARAMS__X86LocalApic__
#define __PARAMS__X86LocalApic__

namespace X86ISA {
class Interrupts;
} // namespace X86ISA

#include <cstddef>
#include "base/types.hh"

#include "params/BasicPioDevice.hh"

struct X86LocalApicParams
    : public BasicPioDeviceParams
{
    X86ISA::Interrupts * create();
    Tick int_latency;
    unsigned int port_int_slave_connection_count;
    unsigned int port_int_master_connection_count;
};

#endif // __PARAMS__X86LocalApic__
