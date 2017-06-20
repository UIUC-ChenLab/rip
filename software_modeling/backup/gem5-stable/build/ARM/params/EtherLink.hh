#ifndef __PARAMS__EtherLink__
#define __PARAMS__EtherLink__

class EtherLink;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/EtherDump.hh"
#include <cstddef>

#include "params/EtherObject.hh"

struct EtherLinkParams
    : public EtherObjectParams
{
    EtherLink * create();
    Tick delay;
    Tick delay_var;
    EtherDump * dump;
    float speed;
    unsigned int port_int1_connection_count;
    unsigned int port_int0_connection_count;
};

#endif // __PARAMS__EtherLink__
