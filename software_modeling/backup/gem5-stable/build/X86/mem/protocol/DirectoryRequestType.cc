/** \file DirectoryRequestType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/DirectoryRequestType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const DirectoryRequestType& obj)
{
    out << DirectoryRequestType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
DirectoryRequestType_to_string(const DirectoryRequestType& obj)
{
    switch(obj) {
      case DirectoryRequestType_Default:
        return "Default";
      default:
        panic("Invalid range for type DirectoryRequestType");
    }
}

// Code to convert from a string to the enumeration
DirectoryRequestType
string_to_DirectoryRequestType(const string& str)
{
    if (str == "Default") {
        return DirectoryRequestType_Default;
    } else {
        panic("Invalid string conversion for %s, type DirectoryRequestType", str);
    }
}

// Code to increment an enumeration type
DirectoryRequestType&
operator++(DirectoryRequestType& e)
{
    assert(e < DirectoryRequestType_NUM);
    return e = DirectoryRequestType(e+1);
}
