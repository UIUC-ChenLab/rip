// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   x86/isa/main.isa

#include "decoder.hh"

#include "arch/x86/decoder.hh"
#include "arch/x86/regs/float.hh"
#include "arch/x86/regs/misc.hh"
#include "arch/x86/regs/segment.hh"
#include "arch/x86/faults.hh"
#include "arch/x86/microcode_rom.hh"
#include "arch/x86/tlb.hh"
#include "base/loader/symtab.hh"
#include "base/cprintf.hh"
#include "base/misc.hh"
#include "cpu/thread_context.hh"  // for Jump::branchTarget()
#include "mem/packet.hh"
#include "sim/full_system.hh"

#if defined(linux) || defined(__APPLE__)
#include <fenv.h>
#endif
#include <algorithm>

using namespace X86ISA;
