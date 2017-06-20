#include "sim/init.hh"

extern "C" {
    void init_param_BasicLink();
}

EmbeddedSwig embed_swig_param_BasicLink(init_param_BasicLink);
