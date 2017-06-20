#include "sim/init.hh"

extern "C" {
    void init_NetworkLink_d_vector();
}

EmbeddedSwig embed_swig_NetworkLink_d_vector(init_NetworkLink_d_vector);
