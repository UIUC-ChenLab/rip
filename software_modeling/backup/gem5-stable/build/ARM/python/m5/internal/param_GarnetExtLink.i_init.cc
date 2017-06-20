#include "sim/init.hh"

extern "C" {
    void init_param_GarnetExtLink();
}

EmbeddedSwig embed_swig_param_GarnetExtLink(init_param_GarnetExtLink);
