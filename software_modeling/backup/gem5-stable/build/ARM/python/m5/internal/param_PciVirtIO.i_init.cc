#include "sim/init.hh"

extern "C" {
    void init_param_PciVirtIO();
}

EmbeddedSwig embed_swig_param_PciVirtIO(init_param_PciVirtIO);
