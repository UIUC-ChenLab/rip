#ifndef __PARAMS__BasicIntLink__
#define __PARAMS__BasicIntLink__

class BasicIntLink;

#include <cstddef>
#include "params/BasicRouter.hh"
#include <cstddef>
#include "params/BasicRouter.hh"

#include "params/BasicLink.hh"

struct BasicIntLinkParams
    : public BasicLinkParams
{
    BasicIntLink * create();
    BasicRouter * node_a;
    BasicRouter * node_b;
};

#endif // __PARAMS__BasicIntLink__
