%module(package="m5.internal") param_I8237

%{
#include "sim/sim_object.hh"
#include "params/I8237.hh"
#include "dev/x86/i8237.hh"
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


%import "python/m5/internal/param_BasicPioDevice.i"

namespace X86ISA {
// avoid name conflicts
%rename(X86ISA_COLONS_I8237) I8237;

// stop swig from creating/wrapping default ctor/dtor
%nodefault I8237;
class I8237
    : public BasicPioDevice
{
  public:
};
} // namespace X86ISA

%include "params/I8237.hh"
