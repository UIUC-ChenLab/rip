#include "sim/init.hh"

extern "C" {
    void init_param_I8042();
}

EmbeddedSwig embed_swig_param_I8042(init_param_I8042);
