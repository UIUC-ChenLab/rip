#include "sim/init.hh"

extern "C" {
    void init_AbstractNVM_vector();
}

EmbeddedSwig embed_swig_AbstractNVM_vector(init_AbstractNVM_vector);
