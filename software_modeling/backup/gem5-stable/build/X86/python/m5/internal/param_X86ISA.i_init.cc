#include "sim/init.hh"

extern "C" {
    void init_param_X86ISA();
}

EmbeddedSwig embed_swig_param_X86ISA(init_param_X86ISA);
