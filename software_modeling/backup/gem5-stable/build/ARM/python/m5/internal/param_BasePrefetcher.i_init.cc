#include "sim/init.hh"

extern "C" {
    void init_param_BasePrefetcher();
}

EmbeddedSwig embed_swig_param_BasePrefetcher(init_param_BasePrefetcher);
