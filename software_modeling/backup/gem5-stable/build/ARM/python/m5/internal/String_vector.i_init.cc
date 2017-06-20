#include "sim/init.hh"

extern "C" {
    void init_String_vector();
}

EmbeddedSwig embed_swig_String_vector(init_String_vector);
