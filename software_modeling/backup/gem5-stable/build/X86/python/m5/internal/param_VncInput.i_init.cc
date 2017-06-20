#include "sim/init.hh"

extern "C" {
    void init_param_VncInput();
}

EmbeddedSwig embed_swig_param_VncInput(init_param_VncInput);
