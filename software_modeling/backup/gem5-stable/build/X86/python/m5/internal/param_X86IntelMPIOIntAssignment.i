%module(package="m5.internal") param_X86IntelMPIOIntAssignment

%{
#include "sim/sim_object.hh"
#include "params/X86IntelMPIOIntAssignment.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "enums/X86IntelMPInterruptType.hh"
#include <cstddef>
#include "enums/X86IntelMPPolarity.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "enums/X86IntelMPTriggerMode.hh"
#include "arch/x86/bios/intelmp.hh"
/**
  * This is a workaround for bug in swig. Prior to gcc 4.6.1 the STL
  * headers like vector, string, etc. used to automatically pull in
  * the cstddef header but starting with gcc 4.6.1 they no longer do.
  * This leads to swig generated a file that does not compile so we
  * explicitly include cstddef. Additionally, including version 2.0.4,
  * swig uses ptrdiff_t without the std:: namespace prefix which is
  * required with gcc 4.6.1. We explicitly provide access to it.
  */
#include <cstddef>
using std::ptrdiff_t;
%}

%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"
%import "python/m5/internal/enum_X86IntelMPInterruptType.i"
%import "python/m5/internal/enum_X86IntelMPPolarity.i"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"
%import "python/m5/internal/enum_X86IntelMPTriggerMode.i"

%import "python/m5/internal/param_X86IntelMPBaseConfigEntry.i"

namespace X86ISA {
namespace IntelMP {
// avoid name conflicts
%rename(X86ISA_COLONS_IntelMP_COLONS_IOIntAssignment) IOIntAssignment;

// stop swig from creating/wrapping default ctor/dtor
%nodefault IOIntAssignment;
class IOIntAssignment
    : public X86ISA::IntelMP::BaseConfigEntry
{
  public:
};
} // namespace IntelMP
} // namespace X86ISA

%include "params/X86IntelMPIOIntAssignment.hh"
