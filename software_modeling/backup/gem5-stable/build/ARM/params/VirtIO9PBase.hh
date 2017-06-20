#ifndef __PARAMS__VirtIO9PBase__
#define __PARAMS__VirtIO9PBase__

class VirtIO9PBase;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>

#include "params/VirtIODeviceBase.hh"

struct VirtIO9PBaseParams
    : public VirtIODeviceBaseParams
{
    unsigned queueSize;
    std::string tag;
};

#endif // __PARAMS__VirtIO9PBase__
