#include "sim/init.hh"

extern "C" {
    void init_MinorFU_vector();
}

EmbeddedSwig embed_swig_MinorFU_vector(init_MinorFU_vector);
