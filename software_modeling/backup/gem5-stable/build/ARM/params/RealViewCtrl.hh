#ifndef __PARAMS__RealViewCtrl__
#define __PARAMS__RealViewCtrl__

class RealViewCtrl;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BasicPioDevice.hh"

struct RealViewCtrlParams
    : public BasicPioDeviceParams
{
    RealViewCtrl * create();
    uint32_t idreg;
    uint32_t proc_id0;
    uint32_t proc_id1;
};

#endif // __PARAMS__RealViewCtrl__
