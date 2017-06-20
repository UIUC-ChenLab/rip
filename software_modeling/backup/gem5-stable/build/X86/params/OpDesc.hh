#ifndef __PARAMS__OpDesc__
#define __PARAMS__OpDesc__

class OpDesc;

#include <cstddef>
#include "enums/OpClass.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>

#include "params/SimObject.hh"

#include "enums/OpClass.hh"

struct OpDescParams
    : public SimObjectParams
{
    OpDesc * create();
    Enums::OpClass opClass;
    Cycles opLat;
    bool pipelined;
};

#endif // __PARAMS__OpDesc__
