#include "sim/init.hh"

extern "C" {
    void init_param_EtherLink();
}

EmbeddedSwig embed_swig_param_EtherLink(init_param_EtherLink);
