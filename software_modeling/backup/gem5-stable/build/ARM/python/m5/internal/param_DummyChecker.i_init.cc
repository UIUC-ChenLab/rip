#include "sim/init.hh"

extern "C" {
    void init_param_DummyChecker();
}

EmbeddedSwig embed_swig_param_DummyChecker(init_param_DummyChecker);
