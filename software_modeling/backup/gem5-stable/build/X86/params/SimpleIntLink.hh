#ifndef __PARAMS__SimpleIntLink__
#define __PARAMS__SimpleIntLink__

class SimpleIntLink;


#include "params/BasicIntLink.hh"

struct SimpleIntLinkParams
    : public BasicIntLinkParams
{
    SimpleIntLink * create();
};

#endif // __PARAMS__SimpleIntLink__
