#ifndef __PARAMS__SimpleExtLink__
#define __PARAMS__SimpleExtLink__

class SimpleExtLink;


#include "params/BasicExtLink.hh"

struct SimpleExtLinkParams
    : public BasicExtLinkParams
{
    SimpleExtLink * create();
};

#endif // __PARAMS__SimpleExtLink__
