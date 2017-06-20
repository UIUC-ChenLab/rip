%module(package="m5.internal") param_SouthBridge

%{
#include "sim/sim_object.hh"
#include "params/SouthBridge.hh"
#include <cstddef>
#include "params/Cmos.hh"
#include <cstddef>
#include "params/I8237.hh"
#include <cstddef>
#include "params/I82094AA.hh"
#include <cstddef>
#include "params/I8042.hh"
#include <cstddef>
#include "params/I8259.hh"
#include <cstddef>
#include "params/I8259.hh"
#include <cstddef>
#include "params/I8254.hh"
#include <cstddef>
#include "params/Platform.hh"
#include <cstddef>
#include "params/PcSpeaker.hh"
#include "dev/x86/south_bridge.hh"
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

%import "python/m5/internal/param_Cmos.i"
%import "python/m5/internal/param_I8237.i"
%import "python/m5/internal/param_I82094AA.i"
%import "python/m5/internal/param_I8042.i"
%import "python/m5/internal/param_I8259.i"
%import "python/m5/internal/param_I8259.i"
%import "python/m5/internal/param_I8254.i"
%import "python/m5/internal/param_Platform.i"
%import "python/m5/internal/param_PcSpeaker.i"

%import "python/m5/internal/param_SimObject.i"


// stop swig from creating/wrapping default ctor/dtor
%nodefault SouthBridge;
class SouthBridge
    : public SimObject
{
  public:
};

%include "params/SouthBridge.hh"
