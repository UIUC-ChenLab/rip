#ifndef __PARAMS__Directory_Controller__
#define __PARAMS__Directory_Controller__

class Directory_Controller;

#include <cstddef>
#include "params/RubyDirectoryMemory.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/RubyController.hh"

struct Directory_ControllerParams
    : public RubyControllerParams
{
    Directory_Controller * create();
    DirectoryMemory * directory;
    Cycles directory_latency;
    Cycles to_memory_controller_latency;
    unsigned int port_dmaRequestToDir_connection_count;
    unsigned int port_requestToDir_connection_count;
    unsigned int port_dmaResponseFromDir_connection_count;
    unsigned int port_forwardFromDir_connection_count;
    unsigned int port_responseFromDir_connection_count;
};

#endif // __PARAMS__Directory_Controller__
