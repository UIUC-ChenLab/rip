#ifndef __PARAMS__ExternalSlave__
#define __PARAMS__ExternalSlave__

class ExternalSlave;

#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include <string>

#include "params/MemObject.hh"

struct ExternalSlaveParams
    : public MemObjectParams
{
    ExternalSlave * create();
    std::vector< AddrRange > addr_ranges;
    std::string port_data;
    std::string port_type;
    unsigned int port_port_connection_count;
};

#endif // __PARAMS__ExternalSlave__
