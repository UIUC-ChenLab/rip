#include "sim/init.hh"

extern "C" {
    void init_EmulatedDriver_vector();
}

EmbeddedSwig embed_swig_EmulatedDriver_vector(init_EmulatedDriver_vector);
