#ifndef __PARAMS__AddrMapper__
#define __PARAMS__AddrMapper__

class AddrMapper;


#include "params/MemObject.hh"

struct AddrMapperParams
    : public MemObjectParams
{
    unsigned int port_master_connection_count;
    unsigned int port_slave_connection_count;
};

#endif // __PARAMS__AddrMapper__
