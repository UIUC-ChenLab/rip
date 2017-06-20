#include "sim/init.hh"

extern "C" {
    void init_param_IsaFake();
}

EmbeddedSwig embed_swig_param_IsaFake(init_param_IsaFake);
