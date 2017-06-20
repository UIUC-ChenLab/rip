#ifndef __PARAMS__FUDesc__
#define __PARAMS__FUDesc__

class FUDesc;

#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "params/OpDesc.hh"

#include "params/SimObject.hh"

struct FUDescParams
    : public SimObjectParams
{
    FUDesc * create();
    int count;
    std::vector< OpDesc * > opList;
};

#endif // __PARAMS__FUDesc__
