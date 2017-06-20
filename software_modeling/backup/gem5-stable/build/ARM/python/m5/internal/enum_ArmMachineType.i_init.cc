#include "sim/init.hh"

extern "C" {
    void init_enum_ArmMachineType();
}

EmbeddedSwig embed_swig_enum_ArmMachineType(init_enum_ArmMachineType);
