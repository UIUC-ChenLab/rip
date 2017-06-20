#ifndef __PARAMS__BasicExtLink__
#define __PARAMS__BasicExtLink__

class BasicExtLink;

#include <cstddef>
#include "params/RubyController.hh"
#include <cstddef>
#include "params/BasicRouter.hh"

#include "params/BasicLink.hh"

struct BasicExtLinkParams
    : public BasicLinkParams
{
    BasicExtLink * create();
    AbstractController * ext_node;
    BasicRouter * int_node;
};

#endif // __PARAMS__BasicExtLink__
