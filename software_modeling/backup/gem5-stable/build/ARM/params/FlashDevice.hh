#ifndef __PARAMS__FlashDevice__
#define __PARAMS__FlashDevice__

class FlashDevice;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "enums/DataDistribution.hh"
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

#include "params/AbstractNVM.hh"

#include "enums/DataDistribution.hh"

struct FlashDeviceParams
    : public AbstractNVMParams
{
    FlashDevice * create();
    int GC_active;
    uint64_t blk_size;
    Enums::DataDistribution data_distribution;
    Tick erase_lat;
    uint32_t num_planes;
    uint64_t page_size;
    Tick read_lat;
    Tick write_lat;
};

#endif // __PARAMS__FlashDevice__
