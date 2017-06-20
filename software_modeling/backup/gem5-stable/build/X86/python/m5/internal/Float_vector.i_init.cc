#include "sim/init.hh"

extern "C" {
    void init_Float_vector();
}

EmbeddedSwig embed_swig_Float_vector(init_Float_vector);
