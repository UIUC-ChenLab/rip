#include "sim/init.hh"

extern "C" {
    void init_param_BaseGarnetNetwork();
}

EmbeddedSwig embed_swig_param_BaseGarnetNetwork(init_param_BaseGarnetNetwork);
