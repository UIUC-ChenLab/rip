#ifndef __PARAMS__DMASequencer__
#define __PARAMS__DMASequencer__

class DMASequencer;

#include <cstddef>
#include "params/RubySystem.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"

#include "params/MemObject.hh"

struct DMASequencerParams
    : public MemObjectParams
{
    DMASequencer * create();
    RubySystem * ruby_system;
    System * system;
    bool using_ruby_tester;
    int version;
    unsigned int port_slave_connection_count;
};

#endif // __PARAMS__DMASequencer__
