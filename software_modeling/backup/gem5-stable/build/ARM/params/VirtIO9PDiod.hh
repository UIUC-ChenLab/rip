#ifndef __PARAMS__VirtIO9PDiod__
#define __PARAMS__VirtIO9PDiod__

class VirtIO9PDiod;

#include <cstddef>
#include <string>
#include <cstddef>
#include <string>

#include "params/VirtIO9PProxy.hh"

struct VirtIO9PDiodParams
    : public VirtIO9PProxyParams
{
    VirtIO9PDiod * create();
    std::string diod;
    std::string root;
};

#endif // __PARAMS__VirtIO9PDiod__
