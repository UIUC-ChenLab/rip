#include "sim/init.hh"

extern "C" {
    void init_param_SouthBridge();
}

EmbeddedSwig embed_swig_param_SouthBridge(init_param_SouthBridge);
