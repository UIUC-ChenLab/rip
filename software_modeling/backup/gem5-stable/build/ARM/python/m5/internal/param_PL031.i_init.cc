#include "sim/init.hh"

extern "C" {
    void init_param_PL031();
}

EmbeddedSwig embed_swig_param_PL031(init_param_PL031);
