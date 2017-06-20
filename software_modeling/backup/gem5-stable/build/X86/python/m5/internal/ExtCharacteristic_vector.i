%module(package="m5.internal") ExtCharacteristic_vector
%{
#include "enums/ExtCharacteristic.hh"
%}

%include "std_container.i"

%import "python/m5/internal/enum_ExtCharacteristic.i"

%include "std_vector.i"

%template(vector_ExtCharacteristic) std::vector< Enums::ExtCharacteristic >;
