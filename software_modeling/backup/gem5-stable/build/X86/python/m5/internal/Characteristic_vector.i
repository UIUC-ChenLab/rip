%module(package="m5.internal") Characteristic_vector
%{
#include "enums/Characteristic.hh"
%}

%include "std_container.i"

%import "python/m5/internal/enum_Characteristic.i"

%include "std_vector.i"

%template(vector_Characteristic) std::vector< Enums::Characteristic >;
