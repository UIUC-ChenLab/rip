#include "sim/init.hh"

extern "C" {
    void init_TimingExpr_vector();
}

EmbeddedSwig embed_swig_TimingExpr_vector(init_TimingExpr_vector);
