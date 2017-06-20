#include "sim/init.hh"

extern "C" {
    void init_enum_MemSched();
}

EmbeddedSwig embed_swig_enum_MemSched(init_enum_MemSched);
