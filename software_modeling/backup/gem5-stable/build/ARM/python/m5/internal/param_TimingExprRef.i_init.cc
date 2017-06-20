#include "sim/init.hh"

extern "C" {
    void init_param_TimingExprRef();
}

EmbeddedSwig embed_swig_param_TimingExprRef(init_param_TimingExprRef);
