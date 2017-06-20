#include "sim/init.hh"

extern "C" {
    void init_event();
}

EmbeddedSwig embed_swig_event(init_event);
