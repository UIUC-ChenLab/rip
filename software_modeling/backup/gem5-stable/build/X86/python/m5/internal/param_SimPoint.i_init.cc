#include "sim/init.hh"

extern "C" {
    void init_param_SimPoint();
}

EmbeddedSwig embed_swig_param_SimPoint(init_param_SimPoint);
