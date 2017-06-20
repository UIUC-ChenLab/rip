#include "sim/init.hh"

extern "C" {
    void init_param_CopyEngine();
}

EmbeddedSwig embed_swig_param_CopyEngine(init_param_CopyEngine);
