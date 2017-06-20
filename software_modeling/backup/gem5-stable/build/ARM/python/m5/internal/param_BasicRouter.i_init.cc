#include "sim/init.hh"

extern "C" {
    void init_param_BasicRouter();
}

EmbeddedSwig embed_swig_param_BasicRouter(init_param_BasicRouter);
