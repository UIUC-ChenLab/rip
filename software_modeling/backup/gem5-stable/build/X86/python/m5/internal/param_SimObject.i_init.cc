#include "sim/init.hh"

extern "C" {
    void init_param_SimObject();
}

EmbeddedSwig embed_swig_param_SimObject(init_param_SimObject);
