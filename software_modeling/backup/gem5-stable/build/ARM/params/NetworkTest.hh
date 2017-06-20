#ifndef __PARAMS__NetworkTest__
#define __PARAMS__NetworkTest__

class NetworkTest;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/MemObject.hh"

struct NetworkTestParams
    : public MemObjectParams
{
    NetworkTest * create();
    int block_offset;
    bool fixed_pkts;
    double inj_rate;
    Counter max_packets;
    int memory_size;
    int num_memories;
    int precision;
    int sim_cycles;
    System * system;
    Counter traffic_type;
    unsigned int port_test_connection_count;
};

#endif // __PARAMS__NetworkTest__
