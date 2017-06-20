#ifndef __PARAMS__Gicv2mFrame__
#define __PARAMS__Gicv2mFrame__

class Gicv2mFrame;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct Gicv2mFrameParams
    : public SimObjectParams
{
    Gicv2mFrame * create();
    Addr addr;
    uint32_t spi_base;
    uint32_t spi_len;
};

#endif // __PARAMS__Gicv2mFrame__
