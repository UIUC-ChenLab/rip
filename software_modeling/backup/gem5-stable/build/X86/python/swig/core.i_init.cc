#include "sim/init.hh"

extern "C" {
    void init_core();
}

EmbeddedSwig embed_swig_core(init_core);
