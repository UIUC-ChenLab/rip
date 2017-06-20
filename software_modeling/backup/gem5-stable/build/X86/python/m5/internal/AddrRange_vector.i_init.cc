#include "sim/init.hh"

extern "C" {
    void init_AddrRange_vector();
}

EmbeddedSwig embed_swig_AddrRange_vector(init_AddrRange_vector);
