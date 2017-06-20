%module(package="m5.internal") DiskImage_vector
%{
#include "params/DiskImage.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_DiskImage.i"

%include "std_vector.i"

%template(vector_DiskImage) std::vector< DiskImage * >;
