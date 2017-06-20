#include "sim/init.hh"

extern "C" {
    void init_param_ClockedObject();
}

EmbeddedSwig embed_swig_param_ClockedObject(init_param_ClockedObject);
