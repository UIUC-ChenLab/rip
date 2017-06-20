#include "sim/init.hh"

extern "C" {
    void init_Int_vector();
}

EmbeddedSwig embed_swig_Int_vector(init_Int_vector);
