#include "sim/init.hh"

extern "C" {
    void init_BasicExtLink_vector();
}

EmbeddedSwig embed_swig_BasicExtLink_vector(init_BasicExtLink_vector);
