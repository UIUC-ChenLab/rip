#include "sim/init.hh"

extern "C" {
    void init_enum_X86IntelMPPolarity();
}

EmbeddedSwig embed_swig_enum_X86IntelMPPolarity(init_enum_X86IntelMPPolarity);
