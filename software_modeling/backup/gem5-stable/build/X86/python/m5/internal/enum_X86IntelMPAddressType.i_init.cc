#include "sim/init.hh"

extern "C" {
    void init_enum_X86IntelMPAddressType();
}

EmbeddedSwig embed_swig_enum_X86IntelMPAddressType(init_enum_X86IntelMPAddressType);
