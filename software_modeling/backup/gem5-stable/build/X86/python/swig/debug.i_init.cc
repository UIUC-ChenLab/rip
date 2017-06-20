#include "sim/init.hh"

extern "C" {
    void init_debug();
}

EmbeddedSwig embed_swig_debug(init_debug);
