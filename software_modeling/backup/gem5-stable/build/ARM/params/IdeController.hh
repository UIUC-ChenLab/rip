#ifndef __PARAMS__IdeController__
#define __PARAMS__IdeController__

class IdeController;

#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "params/IdeDisk.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/PciDevice.hh"

struct IdeControllerParams
    : public PciDeviceParams
{
    IdeController * create();
    uint32_t ctrl_offset;
    std::vector< IdeDisk * > disks;
    uint32_t io_shift;
};

#endif // __PARAMS__IdeController__
