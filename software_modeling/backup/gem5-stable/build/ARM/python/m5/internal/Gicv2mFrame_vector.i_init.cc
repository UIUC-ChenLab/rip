#include "sim/init.hh"

extern "C" {
    void init_Gicv2mFrame_vector();
}

EmbeddedSwig embed_swig_Gicv2mFrame_vector(init_Gicv2mFrame_vector);
