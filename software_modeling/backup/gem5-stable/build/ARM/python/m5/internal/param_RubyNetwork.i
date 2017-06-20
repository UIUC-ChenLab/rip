%module(package="m5.internal") param_RubyNetwork

%{
#include "sim/sim_object.hh"
#include "params/RubyNetwork.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "params/BasicExtLink.hh"
#include <vector>
#include "params/BasicIntLink.hh"
#include <vector>
#include "params/ClockedObject.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "params/BasicRouter.hh"
#include <cstddef>
#include "params/RubySystem.hh"
#include <cstddef>
#include <string>
#include "mem/ruby/network/Network.hh"
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
%import "BasicExtLink_vector.i"
%import "BasicIntLink_vector.i"
%import "ClockedObject_vector.i"
%import "stdint.i"
%import "base/types.hh"
%import "BasicRouter_vector.i"
%import "python/m5/internal/param_RubySystem.i"
%include "std_string.i"

%import "python/m5/internal/param_ClockedObject.i"


// stop swig from creating/wrapping default ctor/dtor
%nodefault Network;
class Network
    : public ClockedObject
{
  public:
};

%include "params/RubyNetwork.hh"
