#include "sim/init.hh"

extern "C" {
    void init_param_TimingExprSrcReg();
}

EmbeddedSwig embed_swig_param_TimingExprSrcReg(init_param_TimingExprSrcReg);
