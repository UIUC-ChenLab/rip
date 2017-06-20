#include "sim/init.hh"

extern "C" {
    void init_param_TimingExpr();
}

EmbeddedSwig embed_swig_param_TimingExpr(init_param_TimingExpr);
