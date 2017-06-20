#include "sim/init.hh"

extern "C" {
    void init_param_RealView();
}

EmbeddedSwig embed_swig_param_RealView(init_param_RealView);
