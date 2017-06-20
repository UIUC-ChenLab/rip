#include "sim/init.hh"

extern "C" {
    void init_enum_X86IntelMPInterruptType();
}

EmbeddedSwig embed_swig_enum_X86IntelMPInterruptType(init_enum_X86IntelMPInterruptType);
