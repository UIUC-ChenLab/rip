// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   x86/isa/main.isa

#include "decoder.hh"

#if defined(linux) || defined(__APPLE__)
#include <fenv.h>
#endif

#if defined(__sun) || defined (__OpenBSD__)
#include <ieeefp.h>
#endif

#include <cmath>
#include <limits>

#include "arch/generic/debugfaults.hh"
#include "arch/x86/regs/misc.hh"
#include "arch/x86/cpuid.hh"
#include "arch/x86/faults.hh"
#include "arch/x86/memhelpers.hh"
#include "arch/x86/tlb.hh"
#include "base/bigint.hh"
#include "base/compiler.hh"
#include "base/condcodes.hh"
#include "cpu/base.hh"
#include "cpu/exetrace.hh"
#include "debug/X86.hh"
#include "mem/packet.hh"
#include "mem/packet_access.hh"
#include "mem/request.hh"
#include "sim/pseudo_inst.hh"
#include "sim/sim_exit.hh"

using namespace X86ISA;
using namespace std;
