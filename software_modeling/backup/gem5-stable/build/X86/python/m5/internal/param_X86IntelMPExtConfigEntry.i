%module(package="m5.internal") param_X86IntelMPExtConfigEntry

%{
#include "sim/sim_object.hh"
#include "params/X86IntelMPExtConfigEntry.hh"
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


%import "python/m5/internal/param_SimObject.i"

namespace X86ISA {
namespace IntelMP {
// avoid name conflicts
%rename(X86ISA_COLONS_IntelMP_COLONS_ExtConfigEntry) ExtConfigEntry;

// stop swig from creating/wrapping default ctor/dtor
%nodefault ExtConfigEntry;
class ExtConfigEntry
    : public SimObject
{
  public:
};
} // namespace IntelMP
} // namespace X86ISA

%include "params/X86IntelMPExtConfigEntry.hh"
