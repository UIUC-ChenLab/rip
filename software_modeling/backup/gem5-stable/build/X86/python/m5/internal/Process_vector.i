%module(package="m5.internal") Process_vector
%{
#include "params/Process.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_Process.i"

%include "std_vector.i"

%template(vector_Process) std::vector< Process * >;
