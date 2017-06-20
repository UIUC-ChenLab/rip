#include "sim/init.hh"

extern "C" {
    void init_param_SimpleExtLink();
}

EmbeddedSwig embed_swig_param_SimpleExtLink(init_param_SimpleExtLink);
