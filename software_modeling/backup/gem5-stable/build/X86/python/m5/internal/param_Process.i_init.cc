#include "sim/init.hh"

extern "C" {
    void init_param_Process();
}

EmbeddedSwig embed_swig_param_Process(init_param_Process);
