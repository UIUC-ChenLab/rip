#include "sim/init.hh"

extern "C" {
    void init_Cycles_vector();
}

EmbeddedSwig embed_swig_Cycles_vector(init_Cycles_vector);
