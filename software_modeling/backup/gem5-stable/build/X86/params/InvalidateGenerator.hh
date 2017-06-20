#ifndef __PARAMS__InvalidateGenerator__
#define __PARAMS__InvalidateGenerator__

class InvalidateGenerator;

#include <cstddef>
#include "base/types.hh"

#include "params/DirectedGenerator.hh"

struct InvalidateGeneratorParams
    : public DirectedGeneratorParams
{
    InvalidateGenerator * create();
    int addr_increment_size;
};

#endif // __PARAMS__InvalidateGenerator__
