#include "sim/init.hh"

extern "C" {
    void init_param_I8259();
}

EmbeddedSwig embed_swig_param_I8259(init_param_I8259);
