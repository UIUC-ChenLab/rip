#include "sim/init.hh"

extern "C" {
    void init_enum_PageManage();
}

EmbeddedSwig embed_swig_enum_PageManage(init_enum_PageManage);
