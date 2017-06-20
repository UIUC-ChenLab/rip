#ifndef __PARAMS__EtherTap__
#define __PARAMS__EtherTap__

class EtherTap;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/EtherDump.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/EtherObject.hh"

struct EtherTapParams
    : public EtherObjectParams
{
    EtherTap * create();
    int bufsz;
    EtherDump * dump;
    uint16_t port;
};

#endif // __PARAMS__EtherTap__
