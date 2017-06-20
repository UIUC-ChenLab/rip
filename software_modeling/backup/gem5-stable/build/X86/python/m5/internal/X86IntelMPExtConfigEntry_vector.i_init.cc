#include "sim/init.hh"

extern "C" {
    void init_X86IntelMPExtConfigEntry_vector();
}

EmbeddedSwig embed_swig_X86IntelMPExtConfigEntry_vector(init_X86IntelMPExtConfigEntry_vector);
