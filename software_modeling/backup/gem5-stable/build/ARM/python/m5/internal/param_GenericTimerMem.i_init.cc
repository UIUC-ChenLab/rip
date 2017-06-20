#include "sim/init.hh"

extern "C" {
    void init_param_GenericTimerMem();
}

EmbeddedSwig embed_swig_param_GenericTimerMem(init_param_GenericTimerMem);
