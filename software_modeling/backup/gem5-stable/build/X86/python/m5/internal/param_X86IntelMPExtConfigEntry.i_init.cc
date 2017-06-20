#include "sim/init.hh"

extern "C" {
    void init_param_X86IntelMPExtConfigEntry();
}

EmbeddedSwig embed_swig_param_X86IntelMPExtConfigEntry(init_param_X86IntelMPExtConfigEntry);
