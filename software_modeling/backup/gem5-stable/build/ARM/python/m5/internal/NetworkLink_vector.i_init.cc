#include "sim/init.hh"

extern "C" {
    void init_NetworkLink_vector();
}

EmbeddedSwig embed_swig_NetworkLink_vector(init_NetworkLink_vector);
