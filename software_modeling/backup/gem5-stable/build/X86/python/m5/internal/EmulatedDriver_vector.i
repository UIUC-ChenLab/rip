%module(package="m5.internal") EmulatedDriver_vector
%{
#include "params/EmulatedDriver.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_EmulatedDriver.i"

%include "std_vector.i"

%template(vector_EmulatedDriver) std::vector< EmulatedDriver * >;
