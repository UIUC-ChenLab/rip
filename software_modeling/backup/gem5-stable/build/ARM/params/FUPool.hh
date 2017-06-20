#ifndef __PARAMS__FUPool__
#define __PARAMS__FUPool__

class FUPool;

#include <vector>
#include "params/FUDesc.hh"

#include "params/SimObject.hh"

struct FUPoolParams
    : public SimObjectParams
{
    FUPool * create();
    std::vector< FUDesc * > FUList;
};

#endif // __PARAMS__FUPool__
