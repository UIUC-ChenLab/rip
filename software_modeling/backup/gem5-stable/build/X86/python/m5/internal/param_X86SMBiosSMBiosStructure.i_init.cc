#include "sim/init.hh"

extern "C" {
    void init_param_X86SMBiosSMBiosStructure();
}

EmbeddedSwig embed_swig_param_X86SMBiosSMBiosStructure(init_param_X86SMBiosSMBiosStructure);
