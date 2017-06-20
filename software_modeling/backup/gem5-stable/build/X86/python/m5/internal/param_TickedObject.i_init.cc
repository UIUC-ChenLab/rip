#include "sim/init.hh"

extern "C" {
    void init_param_TickedObject();
}

EmbeddedSwig embed_swig_param_TickedObject(init_param_TickedObject);
