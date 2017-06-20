#ifndef __PARAMS__CopyEngine__
#define __PARAMS__CopyEngine__

class CopyEngine;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/PciDevice.hh"

struct CopyEngineParams
    : public PciDeviceParams
{
    CopyEngine * create();
    uint8_t ChanCnt;
    uint64_t XferCap;
    Tick latAfterCompletion;
    Tick latBeforeBegin;
    unsigned int port_dma_connection_count;
};

#endif // __PARAMS__CopyEngine__
