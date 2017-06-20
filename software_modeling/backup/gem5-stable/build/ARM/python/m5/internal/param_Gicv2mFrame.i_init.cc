#include "sim/init.hh"

extern "C" {
    void init_param_Gicv2mFrame();
}

EmbeddedSwig embed_swig_param_Gicv2mFrame(init_param_Gicv2mFrame);
