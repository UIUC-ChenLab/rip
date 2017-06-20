#include "sim/init.hh"

extern "C" {
    void init_param_NetworkLink();
}

EmbeddedSwig embed_swig_param_NetworkLink(init_param_NetworkLink);
