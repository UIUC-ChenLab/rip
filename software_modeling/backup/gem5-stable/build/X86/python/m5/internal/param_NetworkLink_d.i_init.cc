#include "sim/init.hh"

extern "C" {
    void init_param_NetworkLink_d();
}

EmbeddedSwig embed_swig_param_NetworkLink_d(init_param_NetworkLink_d);
