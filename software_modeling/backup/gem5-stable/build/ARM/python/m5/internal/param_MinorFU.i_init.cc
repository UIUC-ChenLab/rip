#include "sim/init.hh"

extern "C" {
    void init_param_MinorFU();
}

EmbeddedSwig embed_swig_param_MinorFU(init_param_MinorFU);
