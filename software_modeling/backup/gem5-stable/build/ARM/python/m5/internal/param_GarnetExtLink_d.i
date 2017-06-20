%module(package="m5.internal") param_GarnetExtLink_d

%{
#include "sim/sim_object.hh"
#include "params/GarnetExtLink_d.hh"
#include <vector>
#include "params/CreditLink_d.hh"
#include <vector>
#include "params/NetworkLink_d.hh"
#include "mem/ruby/network/garnet/fixed-pipeline/GarnetLink_d.hh"
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

%import "CreditLink_d_vector.i"
%import "NetworkLink_d_vector.i"

%import "python/m5/internal/param_BasicExtLink.i"


// stop swig from creating/wrapping default ctor/dtor
%nodefault GarnetExtLink_d;
class GarnetExtLink_d
    : public BasicExtLink
{
  public:
};

%include "params/GarnetExtLink_d.hh"
