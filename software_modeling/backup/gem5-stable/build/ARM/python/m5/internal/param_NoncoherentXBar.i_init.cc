#include "sim/init.hh"

extern "C" {
    void init_param_NoncoherentXBar();
}

EmbeddedSwig embed_swig_param_NoncoherentXBar(init_param_NoncoherentXBar);
