#include "sim/init.hh"

extern "C" {
    void init_param_FaultModel();
}

EmbeddedSwig embed_swig_param_FaultModel(init_param_FaultModel);
