#include "sim/init.hh"

extern "C" {
    void init_enum_TimingExprOp();
}

EmbeddedSwig embed_swig_enum_TimingExprOp(init_enum_TimingExprOp);
