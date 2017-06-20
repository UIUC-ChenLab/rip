#include "sim/init.hh"

extern "C" {
    void init_param_X86IntelMPBaseConfigEntry();
}

EmbeddedSwig embed_swig_param_X86IntelMPBaseConfigEntry(init_param_X86IntelMPBaseConfigEntry);
