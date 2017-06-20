#include "sim/init.hh"

extern "C" {
    void init_param_FALRU();
}

EmbeddedSwig embed_swig_param_FALRU(init_param_FALRU);
