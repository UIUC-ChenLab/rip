#include "sim/init.hh"

extern "C" {
    void init_X86IntelMPBaseConfigEntry_vector();
}

EmbeddedSwig embed_swig_X86IntelMPBaseConfigEntry_vector(init_X86IntelMPBaseConfigEntry_vector);
