#ifndef __PARAMS__AtomicSimpleCPU__
#define __PARAMS__AtomicSimpleCPU__

class AtomicSimpleCPU;

#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"

#include "params/BaseSimpleCPU.hh"

struct AtomicSimpleCPUParams
    : public BaseSimpleCPUParams
{
    AtomicSimpleCPU * create();
    bool fastmem;
    bool simulate_data_stalls;
    bool simulate_inst_stalls;
    int width;
};

#endif // __PARAMS__AtomicSimpleCPU__
