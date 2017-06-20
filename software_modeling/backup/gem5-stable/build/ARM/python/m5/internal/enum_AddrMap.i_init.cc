#include "sim/init.hh"

extern "C" {
    void init_enum_AddrMap();
}

EmbeddedSwig embed_swig_enum_AddrMap(init_enum_AddrMap);
