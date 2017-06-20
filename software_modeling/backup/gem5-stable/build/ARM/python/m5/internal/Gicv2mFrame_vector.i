%module(package="m5.internal") Gicv2mFrame_vector
%{
#include "params/Gicv2mFrame.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_Gicv2mFrame.i"

%include "std_vector.i"

%template(vector_Gicv2mFrame) std::vector< Gicv2mFrame * >;
