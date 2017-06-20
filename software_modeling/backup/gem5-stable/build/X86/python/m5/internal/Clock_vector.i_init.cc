#include "sim/init.hh"

extern "C" {
    void init_Clock_vector();
}

EmbeddedSwig embed_swig_Clock_vector(init_Clock_vector);
