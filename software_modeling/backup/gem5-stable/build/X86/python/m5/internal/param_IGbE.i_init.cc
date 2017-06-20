#include "sim/init.hh"

extern "C" {
    void init_param_IGbE();
}

EmbeddedSwig embed_swig_param_IGbE(init_param_IGbE);
