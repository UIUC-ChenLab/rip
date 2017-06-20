#ifndef __PARAMS__RandomRepl__
#define __PARAMS__RandomRepl__

class RandomRepl;


#include "params/BaseSetAssoc.hh"

struct RandomReplParams
    : public BaseSetAssocParams
{
    RandomRepl * create();
};

#endif // __PARAMS__RandomRepl__
