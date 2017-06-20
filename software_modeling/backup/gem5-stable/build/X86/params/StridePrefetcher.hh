#ifndef __PARAMS__StridePrefetcher__
#define __PARAMS__StridePrefetcher__

class StridePrefetcher;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>

#include "params/QueuedPrefetcher.hh"

struct StridePrefetcherParams
    : public QueuedPrefetcherParams
{
    StridePrefetcher * create();
    int degree;
    int max_conf;
    int min_conf;
    int start_conf;
    int table_assoc;
    int table_sets;
    int thresh_conf;
    bool use_master_id;
};

#endif // __PARAMS__StridePrefetcher__
