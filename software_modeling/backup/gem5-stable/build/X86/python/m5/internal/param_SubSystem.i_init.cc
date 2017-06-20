#include "sim/init.hh"

extern "C" {
    void init_param_SubSystem();
}

EmbeddedSwig embed_swig_param_SubSystem(init_param_SubSystem);
