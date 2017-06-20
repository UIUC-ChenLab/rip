// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   arm/isa/main.isa

#include "decoder.hh"

#include <cmath>

#include "arch/arm/faults.hh"
#include "arch/arm/isa_traits.hh"
#include "arch/arm/utility.hh"
#include "arch/generic/memhelpers.hh"
#include "base/condcodes.hh"
#include "cpu/base.hh"
#include "sim/pseudo_inst.hh"
#if defined(linux)
#include <fenv.h>
#endif

#include "base/cp_annotate.hh"
#include "debug/Arm.hh"
#include "mem/packet.hh"
#include "mem/packet_access.hh"
#include "sim/sim_exit.hh"

using namespace ArmISA;

