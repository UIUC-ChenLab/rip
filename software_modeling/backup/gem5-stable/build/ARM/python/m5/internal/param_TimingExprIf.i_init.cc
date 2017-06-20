#include "sim/init.hh"

extern "C" {
    void init_param_TimingExprIf();
}

EmbeddedSwig embed_swig_param_TimingExprIf(init_param_TimingExprIf);
