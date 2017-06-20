#include "sim/init.hh"

extern "C" {
    void init_param_EtherObject();
}

EmbeddedSwig embed_swig_param_EtherObject(init_param_EtherObject);
