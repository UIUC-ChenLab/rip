#include "sim/init.hh"

extern "C" {
    void init_ArmISA_vector();
}

EmbeddedSwig embed_swig_ArmISA_vector(init_ArmISA_vector);
