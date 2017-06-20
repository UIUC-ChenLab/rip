#ifndef __PARAMS__VirtIOBlock__
#define __PARAMS__VirtIOBlock__

class VirtIOBlock;

#include <cstddef>
#include "params/DiskImage.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/VirtIODeviceBase.hh"

struct VirtIOBlockParams
    : public VirtIODeviceBaseParams
{
    VirtIOBlock * create();
    DiskImage * image;
    unsigned queueSize;
};

#endif // __PARAMS__VirtIOBlock__
