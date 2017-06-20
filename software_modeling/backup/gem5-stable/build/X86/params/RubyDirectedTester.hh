#ifndef __PARAMS__RubyDirectedTester__
#define __PARAMS__RubyDirectedTester__

class RubyDirectedTester;

#include <cstddef>
#include "params/DirectedGenerator.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/MemObject.hh"

struct RubyDirectedTesterParams
    : public MemObjectParams
{
    RubyDirectedTester * create();
    DirectedGenerator * generator;
    int requests_to_complete;
    unsigned int port_cpuPort_connection_count;
};

#endif // __PARAMS__RubyDirectedTester__
