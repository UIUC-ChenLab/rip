#ifndef __PARAMS__EtherBus__
#define __PARAMS__EtherBus__

class EtherBus;

#include <cstddef>
#include "params/EtherDump.hh"
#include <cstddef>
#include <cstddef>

#include "params/EtherObject.hh"

struct EtherBusParams
    : public EtherObjectParams
{
    EtherBus * create();
    EtherDump * dump;
    bool loopback;
    float speed;
};

#endif // __PARAMS__EtherBus__
