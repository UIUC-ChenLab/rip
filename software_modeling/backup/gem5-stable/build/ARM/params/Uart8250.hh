#ifndef __PARAMS__Uart8250__
#define __PARAMS__Uart8250__

class Uart8250;


#include "params/Uart.hh"

struct Uart8250Params
    : public UartParams
{
    Uart8250 * create();
};

#endif // __PARAMS__Uart8250__
