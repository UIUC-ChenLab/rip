#include "sim/init.hh"

extern "C" {
    void init_param_Cmos();
}

EmbeddedSwig embed_swig_param_Cmos(init_param_Cmos);
