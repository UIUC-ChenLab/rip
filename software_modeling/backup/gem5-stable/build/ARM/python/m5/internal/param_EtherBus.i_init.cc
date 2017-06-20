#include "sim/init.hh"

extern "C" {
    void init_param_EtherBus();
}

EmbeddedSwig embed_swig_param_EtherBus(init_param_EtherBus);
