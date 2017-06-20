#ifndef __PARAMS__MinorOpClassSet__
#define __PARAMS__MinorOpClassSet__

class MinorOpClassSet;

#include <vector>
#include "params/MinorOpClass.hh"

#include "params/SimObject.hh"

struct MinorOpClassSetParams
    : public SimObjectParams
{
    MinorOpClassSet * create();
    std::vector< MinorOpClass * > opClasses;
};

#endif // __PARAMS__MinorOpClassSet__
