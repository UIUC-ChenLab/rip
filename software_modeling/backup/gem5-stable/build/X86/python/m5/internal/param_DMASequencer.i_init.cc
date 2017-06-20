#include "sim/init.hh"

extern "C" {
    void init_param_DMASequencer();
}

EmbeddedSwig embed_swig_param_DMASequencer(init_param_DMASequencer);
