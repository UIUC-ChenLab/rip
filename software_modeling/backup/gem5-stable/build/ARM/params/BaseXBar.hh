#ifndef __PARAMS__BaseXBar__
#define __PARAMS__BaseXBar__

class BaseXBar;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"

#include "params/MemObject.hh"

struct BaseXBarParams
    : public MemObjectParams
{
    Cycles forward_latency;
    Cycles frontend_latency;
    Cycles response_latency;
    bool use_default_range;
    unsigned width;
    unsigned int port_default_connection_count;
    unsigned int port_master_connection_count;
    unsigned int port_slave_connection_count;
};

#endif // __PARAMS__BaseXBar__
