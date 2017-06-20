#include "sim/init.hh"

extern "C" {
    void init_param_AmbaFake();
}

EmbeddedSwig embed_swig_param_AmbaFake(init_param_AmbaFake);
