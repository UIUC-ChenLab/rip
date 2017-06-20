#ifndef __PARAMS__MinorOpClass__
#define __PARAMS__MinorOpClass__

class MinorOpClass;

#include <cstddef>
#include "enums/OpClass.hh"

#include "params/SimObject.hh"

#include "enums/OpClass.hh"

struct MinorOpClassParams
    : public SimObjectParams
{
    MinorOpClass * create();
    Enums::OpClass opClass;
};

#endif // __PARAMS__MinorOpClass__
