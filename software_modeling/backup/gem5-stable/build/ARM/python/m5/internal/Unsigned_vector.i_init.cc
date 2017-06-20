#include "sim/init.hh"

extern "C" {
    void init_Unsigned_vector();
}

EmbeddedSwig embed_swig_Unsigned_vector(init_Unsigned_vector);
