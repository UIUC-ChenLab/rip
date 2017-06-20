#ifndef __PARAMS__TaggedPrefetcher__
#define __PARAMS__TaggedPrefetcher__

class TaggedPrefetcher;

#include <cstddef>
#include "base/types.hh"

#include "params/QueuedPrefetcher.hh"

struct TaggedPrefetcherParams
    : public QueuedPrefetcherParams
{
    TaggedPrefetcher * create();
    int degree;
};

#endif // __PARAMS__TaggedPrefetcher__
