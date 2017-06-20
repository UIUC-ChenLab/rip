#include "sim/init.hh"

extern "C" {
    void init_MinorOpClass_vector();
}

EmbeddedSwig embed_swig_MinorOpClass_vector(init_MinorOpClass_vector);
