#ifndef __PARAMS__MemTest__
#define __PARAMS__MemTest__

class MemTest;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "params/System.hh"

#include "params/MemObject.hh"

struct MemTestParams
    : public MemObjectParams
{
    MemTest * create();
    Cycles interval;
    Counter max_loads;
    int percent_functional;
    int percent_reads;
    int percent_uncacheable;
    Cycles progress_check;
    Counter progress_interval;
    unsigned size;
    bool suppress_func_warnings;
    System * system;
    unsigned int port_port_connection_count;
};

#endif // __PARAMS__MemTest__
