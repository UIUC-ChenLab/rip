#ifndef __PARAMS__RealView__
#define __PARAMS__RealView__

class RealView;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"

#include "params/Platform.hh"

struct RealViewParams
    : public PlatformParams
{
    RealView * create();
    Addr pci_cfg_base;
    bool pci_cfg_gen_offsets;
    Addr pci_io_base;
    System * system;
};

#endif // __PARAMS__RealView__
