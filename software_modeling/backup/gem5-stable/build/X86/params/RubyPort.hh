#ifndef __PARAMS__RubyPort__
#define __PARAMS__RubyPort__

class RubyPort;

#include <cstddef>
#include "params/RubySystem.hh"
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"

#include "params/MemObject.hh"

struct RubyPortParams
    : public MemObjectParams
{
    RubySystem * ruby_system;
    bool support_data_reqs;
    bool support_inst_reqs;
    System * system;
    bool using_ruby_tester;
    int version;
    unsigned int port_slave_connection_count;
    unsigned int port_pio_slave_port_connection_count;
    unsigned int port_mem_master_port_connection_count;
    unsigned int port_master_connection_count;
    unsigned int port_pio_master_port_connection_count;
    unsigned int port_mem_slave_port_connection_count;
};

#endif // __PARAMS__RubyPort__
