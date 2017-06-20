%module(package="m5.internal") param_PL031

%{
#include "sim/sim_object.hh"
#include "params/PL031.hh"
#include <cstddef>
#include <time.h>
#include "dev/arm/rtc_pl031.hh"
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

%include "python/swig/time.i"

%import "python/m5/internal/param_AmbaIntDevice.i"


// stop swig from creating/wrapping default ctor/dtor
%nodefault PL031;
class PL031
    : public AmbaIntDevice
{
  public:
};

%include "params/PL031.hh"
