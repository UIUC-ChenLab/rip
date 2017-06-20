#include "sim/init.hh"

extern "C" {
    void init_param_FUPool();
}

EmbeddedSwig embed_swig_param_FUPool(init_param_FUPool);
