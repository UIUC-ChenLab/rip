#include "sim/init.hh"

extern "C" {
    void init_enum_StaticInstFlags();
}

EmbeddedSwig embed_swig_enum_StaticInstFlags(init_enum_StaticInstFlags);
