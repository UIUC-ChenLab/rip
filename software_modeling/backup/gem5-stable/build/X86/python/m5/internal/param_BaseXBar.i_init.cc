#include "sim/init.hh"

extern "C" {
    void init_param_BaseXBar();
}

EmbeddedSwig embed_swig_param_BaseXBar(init_param_BaseXBar);
