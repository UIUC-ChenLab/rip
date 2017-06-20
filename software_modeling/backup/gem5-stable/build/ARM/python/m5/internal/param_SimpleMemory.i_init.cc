#include "sim/init.hh"

extern "C" {
    void init_param_SimpleMemory();
}

EmbeddedSwig embed_swig_param_SimpleMemory(init_param_SimpleMemory);
