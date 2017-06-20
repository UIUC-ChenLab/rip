#include "sim/init.hh"

extern "C" {
    void init_BasicIntLink_vector();
}

EmbeddedSwig embed_swig_BasicIntLink_vector(init_BasicIntLink_vector);
