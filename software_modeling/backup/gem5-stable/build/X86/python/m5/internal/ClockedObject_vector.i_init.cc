#include "sim/init.hh"

extern "C" {
    void init_ClockedObject_vector();
}

EmbeddedSwig embed_swig_ClockedObject_vector(init_ClockedObject_vector);
