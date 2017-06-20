#include "sim/init.hh"

extern "C" {
    void init_param_StackDistCalc();
}

EmbeddedSwig embed_swig_param_StackDistCalc(init_param_StackDistCalc);
