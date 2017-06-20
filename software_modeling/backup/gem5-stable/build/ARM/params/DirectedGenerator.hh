#ifndef __PARAMS__DirectedGenerator__
#define __PARAMS__DirectedGenerator__

class DirectedGenerator;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"

#include "params/SimObject.hh"

struct DirectedGeneratorParams
    : public SimObjectParams
{
    int num_cpus;
    System * system;
};

#endif // __PARAMS__DirectedGenerator__
