#ifndef __PARAMS__RubyCache__
#define __PARAMS__RubyCache__

class CacheMemory;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct RubyCacheParams
    : public SimObjectParams
{
    CacheMemory * create();
    int assoc;
    Cycles dataAccessLatency;
    int dataArrayBanks;
    bool is_icache;
    Cycles latency;
    std::string replacement_policy;
    bool resourceStalls;
    uint64_t size;
    int start_index_bit;
    Cycles tagAccessLatency;
    int tagArrayBanks;
};

#endif // __PARAMS__RubyCache__
