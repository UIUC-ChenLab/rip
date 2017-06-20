#include "sim/init.hh"

extern "C" {
    void init_param_EtherDump();
}

EmbeddedSwig embed_swig_param_EtherDump(init_param_EtherDump);
