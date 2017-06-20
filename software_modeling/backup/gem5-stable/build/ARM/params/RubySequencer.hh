#ifndef __PARAMS__RubySequencer__
#define __PARAMS__RubySequencer__

class Sequencer;

#include <cstddef>
#include "params/RubyCache.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/RubyCache.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>

#include "params/RubyPort.hh"

struct RubySequencerParams
    : public RubyPortParams
{
    Sequencer * create();
    CacheMemory * dcache;
    Cycles deadlock_threshold;
    CacheMemory * icache;
    int max_outstanding_requests;
    bool using_network_tester;
};

#endif // __PARAMS__RubySequencer__
