%module(package="m5.internal") param_X86PagetableWalker

%{
#include "sim/sim_object.hh"
#include "params/X86PagetableWalker.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"
#include "arch/x86/pagetable_walker.hh"
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
%import "python/m5/internal/param_System.i"

%import "python/m5/internal/param_MemObject.i"

namespace X86ISA {
// avoid name conflicts
%rename(X86ISA_COLONS_Walker) Walker;

// stop swig from creating/wrapping default ctor/dtor
%nodefault Walker;
class Walker
    : public MemObject
{
  public:
};
} // namespace X86ISA

%include "params/X86PagetableWalker.hh"
