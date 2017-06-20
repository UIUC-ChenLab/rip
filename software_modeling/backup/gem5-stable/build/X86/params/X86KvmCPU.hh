#ifndef __PARAMS__X86KvmCPU__
#define __PARAMS__X86KvmCPU__

class X86KvmCPU;

#include <cstddef>

#include "params/BaseKvmCPU.hh"

struct X86KvmCPUParams
    : public BaseKvmCPUParams
{
    X86KvmCPU * create();
    bool useXSave;
};

#endif // __PARAMS__X86KvmCPU__
