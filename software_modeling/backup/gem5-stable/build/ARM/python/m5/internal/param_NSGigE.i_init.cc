#include "sim/init.hh"

extern "C" {
    void init_param_NSGigE();
}

EmbeddedSwig embed_swig_param_NSGigE(init_param_NSGigE);
