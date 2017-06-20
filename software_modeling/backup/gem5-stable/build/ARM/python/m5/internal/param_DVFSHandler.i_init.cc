#include "sim/init.hh"

extern "C" {
    void init_param_DVFSHandler();
}

EmbeddedSwig embed_swig_param_DVFSHandler(init_param_DVFSHandler);
