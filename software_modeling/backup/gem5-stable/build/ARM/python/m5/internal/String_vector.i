%module(package="m5.internal") String_vector
%{
#include <string>
%}

%include "std_container.i"

%include "std_string.i"

%include "std_vector.i"

%template(vector_String) std::vector< std::string >;
