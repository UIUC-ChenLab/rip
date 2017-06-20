#ifndef __PARAMS__BaseKvmCPU__
#define __PARAMS__BaseKvmCPU__

class BaseKvmCPU;

#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/KvmVM.hh"
#include <cstddef>
#include <cstddef>

#include "params/BaseCPU.hh"

struct BaseKvmCPUParams
    : public BaseCPUParams
{
    double hostFactor;
    Tick hostFreq;
    KvmVM * kvmVM;
    bool useCoalescedMMIO;
    bool usePerfOverflow;
};

#endif // __PARAMS__BaseKvmCPU__
