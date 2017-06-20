#include "sim/init.hh"

extern "C" {
    void init_enum_X86IntelMPRangeList();
}

EmbeddedSwig embed_swig_enum_X86IntelMPRangeList(init_enum_X86IntelMPRangeList);
