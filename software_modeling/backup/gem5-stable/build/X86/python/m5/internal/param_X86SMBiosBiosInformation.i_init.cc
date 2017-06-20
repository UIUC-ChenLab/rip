#include "sim/init.hh"

extern "C" {
    void init_param_X86SMBiosBiosInformation();
}

EmbeddedSwig embed_swig_param_X86SMBiosBiosInformation(init_param_X86SMBiosBiosInformation);
