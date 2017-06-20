#ifndef __PARAMS__MinorFUPool__
#define __PARAMS__MinorFUPool__

class MinorFUPool;

#include <vector>
#include "params/MinorFU.hh"

#include "params/SimObject.hh"

struct MinorFUPoolParams
    : public SimObjectParams
{
    MinorFUPool * create();
    std::vector< MinorFU * > funcUnits;
};

#endif // __PARAMS__MinorFUPool__
