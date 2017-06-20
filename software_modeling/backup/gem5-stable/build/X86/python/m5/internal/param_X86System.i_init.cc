#include "sim/init.hh"

extern "C" {
    void init_param_X86System();
}

EmbeddedSwig embed_swig_param_X86System(init_param_X86System);
