#include "sim/init.hh"

extern "C" {
    void init_param_EtherDevBase();
}

EmbeddedSwig embed_swig_param_EtherDevBase(init_param_EtherDevBase);
