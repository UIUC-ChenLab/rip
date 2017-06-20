#ifndef __PARAMS__MemCheckerMonitor__
#define __PARAMS__MemCheckerMonitor__

class MemCheckerMonitor;

#include <cstddef>
#include "params/MemChecker.hh"
#include <cstddef>

#include "params/MemObject.hh"

struct MemCheckerMonitorParams
    : public MemObjectParams
{
    MemCheckerMonitor * create();
    MemChecker * memchecker;
    bool warn_only;
    unsigned int port_master_connection_count;
    unsigned int port_mem_side_connection_count;
    unsigned int port_slave_connection_count;
    unsigned int port_cpu_side_connection_count;
};

#endif // __PARAMS__MemCheckerMonitor__
