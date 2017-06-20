#include "sim/init.hh"

extern "C" {
    void init_param_LinuxArmSystem();
}

EmbeddedSwig embed_swig_param_LinuxArmSystem(init_param_LinuxArmSystem);
