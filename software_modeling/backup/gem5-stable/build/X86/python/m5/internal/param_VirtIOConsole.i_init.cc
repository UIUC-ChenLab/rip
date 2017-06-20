#include "sim/init.hh"

extern "C" {
    void init_param_VirtIOConsole();
}

EmbeddedSwig embed_swig_param_VirtIOConsole(init_param_VirtIOConsole);
