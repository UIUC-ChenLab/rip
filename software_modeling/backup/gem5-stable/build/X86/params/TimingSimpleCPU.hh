#ifndef __PARAMS__TimingSimpleCPU__
#define __PARAMS__TimingSimpleCPU__

class TimingSimpleCPU;


#include "params/BaseSimpleCPU.hh"

struct TimingSimpleCPUParams
    : public BaseSimpleCPUParams
{
    TimingSimpleCPU * create();
};

#endif // __PARAMS__TimingSimpleCPU__
