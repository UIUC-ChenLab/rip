#include "sim/init.hh"

extern "C" {
    void init_param_BranchPredictor();
}

EmbeddedSwig embed_swig_param_BranchPredictor(init_param_BranchPredictor);
