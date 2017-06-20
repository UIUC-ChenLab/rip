#include "sim/init.hh"

extern "C" {
    void init_X86ISA_vector();
}

EmbeddedSwig embed_swig_X86ISA_vector(init_X86ISA_vector);
