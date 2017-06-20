/** \file MemoryRequestType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/MemoryRequestType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const MemoryRequestType& obj)
{
    out << MemoryRequestType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
MemoryRequestType_to_string(const MemoryRequestType& obj)
{
    switch(obj) {
      case MemoryRequestType_MEMORY_READ:
        return "MEMORY_READ";
      case MemoryRequestType_MEMORY_WB:
        return "MEMORY_WB";
      case MemoryRequestType_MEMORY_DATA:
        return "MEMORY_DATA";
      case MemoryRequestType_MEMORY_ACK:
        return "MEMORY_ACK";
      default:
        panic("Invalid range for type MemoryRequestType");
    }
}

// Code to convert from a string to the enumeration
MemoryRequestType
string_to_MemoryRequestType(const string& str)
{
    if (str == "MEMORY_READ") {
        return MemoryRequestType_MEMORY_READ;
    } else if (str == "MEMORY_WB") {
        return MemoryRequestType_MEMORY_WB;
    } else if (str == "MEMORY_DATA") {
        return MemoryRequestType_MEMORY_DATA;
    } else if (str == "MEMORY_ACK") {
        return MemoryRequestType_MEMORY_ACK;
    } else {
        panic("Invalid string conversion for %s, type MemoryRequestType", str);
    }
}

// Code to increment an enumeration type
MemoryRequestType&
operator++(MemoryRequestType& e)
{
    assert(e < MemoryRequestType_NUM);
    return e = MemoryRequestType(e+1);
}
