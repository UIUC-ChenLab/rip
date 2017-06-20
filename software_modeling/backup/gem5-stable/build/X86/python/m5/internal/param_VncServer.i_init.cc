#include "sim/init.hh"

extern "C" {
    void init_param_VncServer();
}

EmbeddedSwig embed_swig_param_VncServer(init_param_VncServer);
