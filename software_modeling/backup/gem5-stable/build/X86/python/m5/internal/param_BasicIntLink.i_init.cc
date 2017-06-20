#include "sim/init.hh"

extern "C" {
    void init_param_BasicIntLink();
}

EmbeddedSwig embed_swig_param_BasicIntLink(init_param_BasicIntLink);
