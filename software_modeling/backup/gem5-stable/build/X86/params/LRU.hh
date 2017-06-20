#ifndef __PARAMS__LRU__
#define __PARAMS__LRU__

class LRU;


#include "params/BaseSetAssoc.hh"

struct LRUParams
    : public BaseSetAssocParams
{
    LRU * create();
};

#endif // __PARAMS__LRU__
