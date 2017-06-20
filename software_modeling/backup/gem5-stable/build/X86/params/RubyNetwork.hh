#ifndef __PARAMS__RubyNetwork__
#define __PARAMS__RubyNetwork__

class Network;

#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "params/BasicExtLink.hh"
#include <vector>
#include "params/BasicIntLink.hh"
#include <vector>
#include "params/ClockedObject.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "params/BasicRouter.hh"
#include <cstddef>
#include "params/RubySystem.hh"
#include <cstddef>
#include <string>

#include "params/ClockedObject.hh"

struct RubyNetworkParams
    : public ClockedObjectParams
{
    int control_msg_size;
    std::vector< BasicExtLink * > ext_links;
    std::vector< BasicIntLink * > int_links;
    std::vector< ClockedObject * > netifs;
    int number_of_virtual_networks;
    std::vector< BasicRouter * > routers;
    RubySystem * ruby_system;
    std::string topology;
    unsigned int port_master_connection_count;
    unsigned int port_slave_connection_count;
};

#endif // __PARAMS__RubyNetwork__
