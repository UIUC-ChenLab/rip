#include "sim/init.hh"

extern "C" {
    void init_param_Switch();
}

EmbeddedSwig embed_swig_param_Switch(init_param_Switch);
