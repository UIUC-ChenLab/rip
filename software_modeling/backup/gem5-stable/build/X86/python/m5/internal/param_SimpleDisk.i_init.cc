#include "sim/init.hh"

extern "C" {
    void init_param_SimpleDisk();
}

EmbeddedSwig embed_swig_param_SimpleDisk(init_param_SimpleDisk);
