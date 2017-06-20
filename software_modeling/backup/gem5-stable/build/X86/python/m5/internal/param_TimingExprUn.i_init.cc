#include "sim/init.hh"

extern "C" {
    void init_param_TimingExprUn();
}

EmbeddedSwig embed_swig_param_TimingExprUn(init_param_TimingExprUn);
