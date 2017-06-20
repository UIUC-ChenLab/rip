#include "sim/init.hh"

extern "C" {
    void init_OpDesc_vector();
}

EmbeddedSwig embed_swig_OpDesc_vector(init_OpDesc_vector);
