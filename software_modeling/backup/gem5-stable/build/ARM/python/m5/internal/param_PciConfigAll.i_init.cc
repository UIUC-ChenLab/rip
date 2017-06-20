#include "sim/init.hh"

extern "C" {
    void init_param_PciConfigAll();
}

EmbeddedSwig embed_swig_param_PciConfigAll(init_param_PciConfigAll);
