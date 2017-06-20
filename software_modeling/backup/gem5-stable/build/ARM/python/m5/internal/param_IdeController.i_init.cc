#include "sim/init.hh"

extern "C" {
    void init_param_IdeController();
}

EmbeddedSwig embed_swig_param_IdeController(init_param_IdeController);
