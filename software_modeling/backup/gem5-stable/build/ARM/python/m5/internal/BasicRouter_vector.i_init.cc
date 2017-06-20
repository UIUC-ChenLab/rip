#include "sim/init.hh"

extern "C" {
    void init_BasicRouter_vector();
}

EmbeddedSwig embed_swig_BasicRouter_vector(init_BasicRouter_vector);
