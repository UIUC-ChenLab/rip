#include "sim/init.hh"

extern "C" {
    void init_param_FreebsdArmSystem();
}

EmbeddedSwig embed_swig_param_FreebsdArmSystem(init_param_FreebsdArmSystem);
