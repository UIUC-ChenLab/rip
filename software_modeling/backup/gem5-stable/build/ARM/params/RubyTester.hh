#ifndef __PARAMS__RubyTester__
#define __PARAMS__RubyTester__

class RubyTester;

#include <cstddef>
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

struct RubyTesterParams
    : public MemObjectParams
{
    RubyTester * create();
    bool check_flush;
    int checks_to_complete;
    int deadlock_threshold;
    int num_cpus;
    System * system;
    int wakeup_frequency;
    unsigned int port_cpuInstPort_connection_count;
    unsigned int port_cpuDataPort_connection_count;
};

#endif // __PARAMS__RubyTester__
