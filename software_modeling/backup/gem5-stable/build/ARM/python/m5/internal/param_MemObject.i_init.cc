#include "sim/init.hh"

extern "C" {
    void init_param_MemObject();
}

EmbeddedSwig embed_swig_param_MemObject(init_param_MemObject);
