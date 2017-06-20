%module(package="m5.internal") param_ArmInterrupts

%{
#include "sim/sim_object.hh"
#include "params/ArmInterrupts.hh"
#include "arch/arm/interrupts.hh"
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

namespace ArmISA {
// avoid name conflicts
%rename(ArmISA_COLONS_Interrupts) Interrupts;

// stop swig from creating/wrapping default ctor/dtor
%nodefault Interrupts;
class Interrupts
    : public SimObject
{
  public:
};
} // namespace ArmISA

%include "params/ArmInterrupts.hh"
