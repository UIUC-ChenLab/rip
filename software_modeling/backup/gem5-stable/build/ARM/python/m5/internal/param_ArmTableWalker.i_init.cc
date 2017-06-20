#include "sim/init.hh"

extern "C" {
    void init_param_ArmTableWalker();
}

EmbeddedSwig embed_swig_param_ArmTableWalker(init_param_ArmTableWalker);
