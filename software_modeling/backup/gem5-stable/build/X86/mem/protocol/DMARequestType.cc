/** \file DMARequestType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/DMARequestType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const DMARequestType& obj)
{
    out << DMARequestType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
DMARequestType_to_string(const DMARequestType& obj)
{
    switch(obj) {
      case DMARequestType_READ:
        return "READ";
      case DMARequestType_WRITE:
        return "WRITE";
      case DMARequestType_NULL:
        return "NULL";
      default:
        panic("Invalid range for type DMARequestType");
    }
}

// Code to convert from a string to the enumeration
DMARequestType
string_to_DMARequestType(const string& str)
{
    if (str == "READ") {
        return DMARequestType_READ;
    } else if (str == "WRITE") {
        return DMARequestType_WRITE;
    } else if (str == "NULL") {
        return DMARequestType_NULL;
    } else {
        panic("Invalid string conversion for %s, type DMARequestType", str);
    }
}

// Code to increment an enumeration type
DMARequestType&
operator++(DMARequestType& e)
{
    assert(e < DMARequestType_NUM);
    return e = DMARequestType(e+1);
}
