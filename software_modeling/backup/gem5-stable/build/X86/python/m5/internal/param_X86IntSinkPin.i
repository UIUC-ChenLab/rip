%module(package="m5.internal") param_X86IntSinkPin

%{
#include "sim/sim_object.hh"
#include "params/X86IntSinkPin.hh"
#include <cstddef>
#include "params/SimObject.hh"
#include <cstddef>
#include "base/types.hh"
#include "dev/x86/intdev.hh"
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
%import "stdint.i"
%import "base/types.hh"

%import "python/m5/internal/param_SimObject.i"

namespace X86ISA {
// avoid name conflicts
%rename(X86ISA_COLONS_IntSinkPin) IntSinkPin;

// stop swig from creating/wrapping default ctor/dtor
%nodefault IntSinkPin;
class IntSinkPin
    : public SimObject
{
  public:
};
} // namespace X86ISA

%include "params/X86IntSinkPin.hh"
