#include "sim/init.hh"

extern "C" {
    void init_param_RealViewCtrl();
}

EmbeddedSwig embed_swig_param_RealViewCtrl(init_param_RealViewCtrl);
