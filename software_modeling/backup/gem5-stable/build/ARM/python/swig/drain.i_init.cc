#include "sim/init.hh"

extern "C" {
    void init_drain();
}

EmbeddedSwig embed_swig_drain(init_drain);
