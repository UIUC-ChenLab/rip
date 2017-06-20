#include "sim/init.hh"

extern "C" {
    void init_enum_IdeID();
}

EmbeddedSwig embed_swig_enum_IdeID(init_enum_IdeID);
