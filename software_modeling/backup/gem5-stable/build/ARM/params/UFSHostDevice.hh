#ifndef __PARAMS__UFSHostDevice__
#define __PARAMS__UFSHostDevice__

class UFSHostDevice;

#include <cstddef>
#include "params/BaseGic.hh"
#include <vector>
#include "params/DiskImage.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "params/AbstractNVM.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/DmaDevice.hh"

struct UFSHostDeviceParams
    : public DmaDeviceParams
{
    UFSHostDevice * create();
    BaseGic * gic;
    std::vector< DiskImage * > image;
    uint32_t img_blk_size;
    uint32_t int_num;
    std::vector< AbstractNVM * > internalflash;
    Addr pio_addr;
    Tick pio_latency;
    uint32_t ufs_slots;
};

#endif // __PARAMS__UFSHostDevice__
