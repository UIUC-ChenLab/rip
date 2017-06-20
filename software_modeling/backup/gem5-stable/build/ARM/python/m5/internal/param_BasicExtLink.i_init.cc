#include "sim/init.hh"

extern "C" {
    void init_param_BasicExtLink();
}

EmbeddedSwig embed_swig_param_BasicExtLink(init_param_BasicExtLink);
