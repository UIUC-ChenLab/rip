// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   x86/isa/main.isa

#include "base/bitfield.hh"

#include <cstring>
#include <iostream>
#include <sstream>

#include "arch/generic/debugfaults.hh"
#include "arch/x86/insts/macroop.hh"
#include "arch/x86/insts/microfpop.hh"
#include "arch/x86/insts/microldstop.hh"
#include "arch/x86/insts/micromediaop.hh"
#include "arch/x86/insts/microregop.hh"
#include "arch/x86/insts/static_inst.hh"
#include "arch/x86/emulenv.hh"
#include "arch/x86/isa_traits.hh"
#include "arch/x86/registers.hh"
#include "arch/x86/types.hh"
#include "arch/x86/utility.hh"
#include "base/misc.hh"
#include "cpu/static_inst.hh"
#include "mem/packet.hh"
#include "sim/faults.hh"

using X86ISA::InstRegIndex;
