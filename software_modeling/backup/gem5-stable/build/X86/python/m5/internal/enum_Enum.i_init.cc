#include "sim/init.hh"

extern "C" {
    void init_enum_Enum();
}

EmbeddedSwig embed_swig_enum_Enum(init_enum_Enum);
