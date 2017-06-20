#include "sim/init.hh"

extern "C" {
    void init_param_DerivO3CPU();
}

EmbeddedSwig embed_swig_param_DerivO3CPU(init_param_DerivO3CPU);
