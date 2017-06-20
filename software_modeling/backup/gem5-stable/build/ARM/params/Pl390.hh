#ifndef __PARAMS__Pl390__
#define __PARAMS__Pl390__

class Pl390;

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
#include <cstddef>
#include "base/types.hh"

#include "params/BaseGic.hh"

struct Pl390Params
    : public BaseGicParams
{
    Pl390 * create();
    Addr cpu_addr;
    Tick cpu_pio_delay;
    Addr dist_addr;
    Tick dist_pio_delay;
    Tick int_latency;
    uint32_t it_lines;
};

#endif // __PARAMS__Pl390__
