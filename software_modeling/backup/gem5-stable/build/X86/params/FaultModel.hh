#ifndef __PARAMS__FaultModel__
#define __PARAMS__FaultModel__

class FaultModel;

#include <vector>
#include <vector>
#include "base/types.hh"

#include "params/SimObject.hh"

struct FaultModelParams
    : public SimObjectParams
{
    FaultModel * create();
    std::vector< double > baseline_fault_vector_database;
    std::vector< int > temperature_weights_database;
};

#endif // __PARAMS__FaultModel__
