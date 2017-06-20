#ifndef __PARAMS__RubySystem__
#define __PARAMS__RubySystem__

class RubySystem;

#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/SimpleMemory.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>

#include "params/ClockedObject.hh"

struct RubySystemParams
    : public ClockedObjectParams
{
    RubySystem * create();
    bool access_backing_store;
    bool all_instructions;
    uint32_t block_size_bytes;
    bool hot_lines;
    uint32_t memory_size_bits;
    int num_of_sequencers;
    SimpleMemory * phys_mem;
    int random_seed;
    bool randomization;
};

#endif // __PARAMS__RubySystem__
