%module(package="m5.internal") IdeDisk_vector
%{
#include "params/IdeDisk.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_IdeDisk.i"

%include "std_vector.i"

%template(vector_IdeDisk) std::vector< IdeDisk * >;
