#include "sim/init.hh"

extern "C" {
    void init_range();
}

EmbeddedSwig embed_swig_range(init_range);
