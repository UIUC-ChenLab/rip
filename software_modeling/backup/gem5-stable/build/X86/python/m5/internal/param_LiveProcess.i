%module(package="m5.internal") param_LiveProcess

%{
#include "sim/sim_object.hh"
#include "params/LiveProcess.hh"
#include <vector>
#include <string>
#include <cstddef>
#include <string>
#include <vector>
#include "params/EmulatedDriver.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include "sim/process.hh"
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

%import "String_vector.i"
%include "std_string.i"
%import "EmulatedDriver_vector.i"
%import "stdint.i"
%import "base/types.hh"
%import "String_vector.i"
%import "stdint.i"
%import "base/types.hh"
%include "std_string.i"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"

%import "python/m5/internal/param_Process.i"


// stop swig from creating/wrapping default ctor/dtor
%nodefault LiveProcess;
class LiveProcess
    : public Process
{
  public:
};

%include "params/LiveProcess.hh"
