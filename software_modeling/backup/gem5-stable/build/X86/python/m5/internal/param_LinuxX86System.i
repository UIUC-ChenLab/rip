%module(package="m5.internal") param_LinuxX86System

%{
#include "sim/sim_object.hh"
#include "params/LinuxX86System.hh"
#include <cstddef>
#include "params/X86E820Table.hh"
#include "arch/x86/linux/system.hh"
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

%import "python/m5/internal/param_X86E820Table.i"

%import "python/m5/internal/param_X86System.i"


// stop swig from creating/wrapping default ctor/dtor
%nodefault LinuxX86System;
class LinuxX86System
    : public X86System
{
  public:
};

%include "params/LinuxX86System.hh"
