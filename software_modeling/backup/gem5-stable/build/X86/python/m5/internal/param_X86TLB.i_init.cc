#include "sim/init.hh"

extern "C" {
    void init_param_X86TLB();
}

EmbeddedSwig embed_swig_param_X86TLB(init_param_X86TLB);
