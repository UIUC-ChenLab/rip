#ifndef __PARAMS__I82094AA__
#define __PARAMS__I82094AA__

namespace X86ISA {
class I82094AA;
} // namespace X86ISA

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/I8259.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BasicPioDevice.hh"

struct I82094AAParams
    : public BasicPioDeviceParams
{
    X86ISA::I82094AA * create();
    int apic_id;
    X86ISA::I8259 * external_int_pic;
    Tick int_latency;
    unsigned int port_int_master_connection_count;
};

#endif // __PARAMS__I82094AA__
