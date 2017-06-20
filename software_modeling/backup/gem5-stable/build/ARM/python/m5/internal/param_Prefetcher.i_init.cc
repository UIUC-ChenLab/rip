#include "sim/init.hh"

extern "C" {
    void init_param_Prefetcher();
}

EmbeddedSwig embed_swig_param_Prefetcher(init_param_Prefetcher);
