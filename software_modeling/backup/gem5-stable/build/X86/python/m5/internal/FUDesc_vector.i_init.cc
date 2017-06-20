#include "sim/init.hh"

extern "C" {
    void init_FUDesc_vector();
}

EmbeddedSwig embed_swig_FUDesc_vector(init_FUDesc_vector);
