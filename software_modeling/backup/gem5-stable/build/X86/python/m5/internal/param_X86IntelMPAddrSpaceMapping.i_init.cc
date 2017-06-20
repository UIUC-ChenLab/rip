#include "sim/init.hh"

extern "C" {
    void init_param_X86IntelMPAddrSpaceMapping();
}

EmbeddedSwig embed_swig_param_X86IntelMPAddrSpaceMapping(init_param_X86IntelMPAddrSpaceMapping);
