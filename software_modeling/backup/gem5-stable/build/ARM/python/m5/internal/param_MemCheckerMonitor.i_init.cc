#include "sim/init.hh"

extern "C" {
    void init_param_MemCheckerMonitor();
}

EmbeddedSwig embed_swig_param_MemCheckerMonitor(init_param_MemCheckerMonitor);
