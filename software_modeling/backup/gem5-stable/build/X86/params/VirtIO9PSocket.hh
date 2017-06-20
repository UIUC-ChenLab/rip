#ifndef __PARAMS__VirtIO9PSocket__
#define __PARAMS__VirtIO9PSocket__

class VirtIO9PSocket;

#include <cstddef>
#include <string>
#include <cstddef>
#include <string>

#include "params/VirtIO9PProxy.hh"

struct VirtIO9PSocketParams
    : public VirtIO9PProxyParams
{
    VirtIO9PSocket * create();
    std::string port;
    std::string server;
};

#endif // __PARAMS__VirtIO9PSocket__
