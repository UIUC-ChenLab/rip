#include "sim/init.hh"

extern "C" {
    void init_param_VirtIODeviceBase();
}

EmbeddedSwig embed_swig_param_VirtIODeviceBase(init_param_VirtIODeviceBase);
