#ifndef __PARAMS__Pl011__
#define __PARAMS__Pl011__

class Pl011;

#include <cstddef>
#include <cstddef>
#include "params/BaseGic.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/Uart.hh"

struct Pl011Params
    : public UartParams
{
    Pl011 * create();
    bool end_on_eot;
    BaseGic * gic;
    Tick int_delay;
    uint32_t int_num;
};

#endif // __PARAMS__Pl011__
