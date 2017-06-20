%module(package="m5.internal") param_UFSHostDevice

%{
#include "sim/sim_object.hh"
#include "params/UFSHostDevice.hh"
#include <cstddef>
#include "params/BaseGic.hh"
#include <vector>
#include "params/DiskImage.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "params/AbstractNVM.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include "dev/arm/ufs_device.hh"
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

%import "python/m5/internal/param_BaseGic.i"
%import "DiskImage_vector.i"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"
%import "AbstractNVM_vector.i"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"

%import "python/m5/internal/param_DmaDevice.i"


// stop swig from creating/wrapping default ctor/dtor
%nodefault UFSHostDevice;
class UFSHostDevice
    : public DmaDevice
{
  public:
};

%include "params/UFSHostDevice.hh"
