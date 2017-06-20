#ifndef __PARAMS__VncServer__
#define __PARAMS__VncServer__

class VncServer;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/VncInput.hh"

struct VncServerParams
    : public VncInputParams
{
    VncServer * create();
    int number;
    uint16_t port;
};

#endif // __PARAMS__VncServer__
