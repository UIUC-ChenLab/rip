#include "sim/init.hh"

extern "C" {
    void init_param_TimingExprBin();
}

EmbeddedSwig embed_swig_param_TimingExprBin(init_param_TimingExprBin);
