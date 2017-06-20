#include "sim/init.hh"

extern "C" {
    void init_SrcClockDomain_vector();
}

EmbeddedSwig embed_swig_SrcClockDomain_vector(init_SrcClockDomain_vector);
