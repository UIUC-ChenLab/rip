#include "sim/init.hh"

extern "C" {
    void init_enum_X86IntelMPTriggerMode();
}

EmbeddedSwig embed_swig_enum_X86IntelMPTriggerMode(init_enum_X86IntelMPTriggerMode);
