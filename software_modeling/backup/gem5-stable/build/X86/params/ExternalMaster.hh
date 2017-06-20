#ifndef __PARAMS__ExternalMaster__
#define __PARAMS__ExternalMaster__

class ExternalMaster;

#include <cstddef>
#include <string>
#include <cstddef>
#include <string>

#include "params/MemObject.hh"

struct ExternalMasterParams
    : public MemObjectParams
{
    ExternalMaster * create();
    std::string port_data;
    std::string port_type;
    unsigned int port_port_connection_count;
};

#endif // __PARAMS__ExternalMaster__
