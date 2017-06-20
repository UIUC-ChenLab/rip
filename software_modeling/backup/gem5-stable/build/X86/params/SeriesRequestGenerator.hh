#ifndef __PARAMS__SeriesRequestGenerator__
#define __PARAMS__SeriesRequestGenerator__

class SeriesRequestGenerator;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/DirectedGenerator.hh"

struct SeriesRequestGeneratorParams
    : public DirectedGeneratorParams
{
    SeriesRequestGenerator * create();
    int addr_increment_size;
    uint32_t num_series;
    int percent_writes;
};

#endif // __PARAMS__SeriesRequestGenerator__
