#include "sim/init.hh"

extern "C" {
    void init_param_GenericTimer();
}

EmbeddedSwig embed_swig_param_GenericTimer(init_param_GenericTimer);
