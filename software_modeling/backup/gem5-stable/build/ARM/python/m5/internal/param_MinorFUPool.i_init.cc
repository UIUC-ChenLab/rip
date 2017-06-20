#include "sim/init.hh"

extern "C" {
    void init_param_MinorFUPool();
}

EmbeddedSwig embed_swig_param_MinorFUPool(init_param_MinorFUPool);
