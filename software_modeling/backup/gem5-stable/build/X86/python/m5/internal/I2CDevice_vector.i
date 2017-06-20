%module(package="m5.internal") I2CDevice_vector
%{
#include "params/I2CDevice.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_I2CDevice.i"

%include "std_vector.i"

%template(vector_I2CDevice) std::vector< I2CDevice * >;
