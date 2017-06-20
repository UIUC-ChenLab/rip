#include "sim/init.hh"

extern "C" {
    void init_param_SimpleNetwork();
}

EmbeddedSwig embed_swig_param_SimpleNetwork(init_param_SimpleNetwork);
