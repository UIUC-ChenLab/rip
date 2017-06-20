#ifndef __PARAMS__CpuLocalTimer__
#define __PARAMS__CpuLocalTimer__

class CpuLocalTimer;

#include <cstddef>
#include "params/BaseGic.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BasicPioDevice.hh"

struct CpuLocalTimerParams
    : public BasicPioDeviceParams
{
    CpuLocalTimer * create();
    BaseGic * gic;
    uint32_t int_num_timer;
    uint32_t int_num_watchdog;
};

#endif // __PARAMS__CpuLocalTimer__
