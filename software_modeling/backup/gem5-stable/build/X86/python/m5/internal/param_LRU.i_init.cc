#include "sim/init.hh"

extern "C" {
    void init_param_LRU();
}

EmbeddedSwig embed_swig_param_LRU(init_param_LRU);
