%module(package="m5.internal") param_X86SMBiosBiosInformation

%{
#include "sim/sim_object.hh"
#include "params/X86SMBiosBiosInformation.hh"
#include <vector>
#include "enums/ExtCharacteristic.hh"
#include <vector>
#include "enums/Characteristic.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include <string>
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

%import "ExtCharacteristic_vector.i"
%import "Characteristic_vector.i"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"
%include "std_string.i"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"
%include "std_string.i"
%include "std_string.i"

%import "python/m5/internal/param_X86SMBiosSMBiosStructure.i"

namespace X86ISA {
namespace SMBios {
// avoid name conflicts
%rename(X86ISA_COLONS_SMBios_COLONS_BiosInformation) BiosInformation;

// stop swig from creating/wrapping default ctor/dtor
%nodefault BiosInformation;
class BiosInformation
    : public X86ISA::SMBios::SMBiosStructure
{
  public:
};
} // namespace SMBios
} // namespace X86ISA

%include "params/X86SMBiosBiosInformation.hh"
