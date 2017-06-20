#include "sim/init.hh"

extern "C" {
    void init_param_X86IntelMPCompatAddrSpaceMod();
}

EmbeddedSwig embed_swig_param_X86IntelMPCompatAddrSpaceMod(init_param_X86IntelMPCompatAddrSpaceMod);
