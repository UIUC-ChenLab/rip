%module(package="m5.internal") param_X86SMBiosSMBiosTable

%{
#include "sim/sim_object.hh"
#include "params/X86SMBiosSMBiosTable.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "params/X86SMBiosSMBiosStructure.hh"
#include "arch/x86/bios/smbios.hh"
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
%import "X86SMBiosSMBiosStructure_vector.i"

%import "python/m5/internal/param_SimObject.i"

namespace X86ISA {
namespace SMBios {
// avoid name conflicts
%rename(X86ISA_COLONS_SMBios_COLONS_SMBiosTable) SMBiosTable;

// stop swig from creating/wrapping default ctor/dtor
%nodefault SMBiosTable;
class SMBiosTable
    : public SimObject
{
  public:
};
} // namespace SMBios
} // namespace X86ISA

%include "params/X86SMBiosSMBiosTable.hh"
