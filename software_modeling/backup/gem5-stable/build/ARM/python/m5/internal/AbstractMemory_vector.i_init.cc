#include "sim/init.hh"

extern "C" {
    void init_AbstractMemory_vector();
}

EmbeddedSwig embed_swig_AbstractMemory_vector(init_AbstractMemory_vector);
