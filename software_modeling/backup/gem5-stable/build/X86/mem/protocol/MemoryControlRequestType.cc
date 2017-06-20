/** \file MemoryControlRequestType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/MemoryControlRequestType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const MemoryControlRequestType& obj)
{
    out << MemoryControlRequestType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
MemoryControlRequestType_to_string(const MemoryControlRequestType& obj)
{
    switch(obj) {
      case MemoryControlRequestType_Default:
        return "Default";
      default:
        panic("Invalid range for type MemoryControlRequestType");
    }
}

// Code to convert from a string to the enumeration
MemoryControlRequestType
string_to_MemoryControlRequestType(const string& str)
{
    if (str == "Default") {
        return MemoryControlRequestType_Default;
    } else {
        panic("Invalid string conversion for %s, type MemoryControlRequestType", str);
    }
}

// Code to increment an enumeration type
MemoryControlRequestType&
operator++(MemoryControlRequestType& e)
{
    assert(e < MemoryControlRequestType_NUM);
    return e = MemoryControlRequestType(e+1);
}
