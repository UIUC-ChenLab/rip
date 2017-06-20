/** \file DMAResponseType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/DMAResponseType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const DMAResponseType& obj)
{
    out << DMAResponseType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
DMAResponseType_to_string(const DMAResponseType& obj)
{
    switch(obj) {
      case DMAResponseType_DATA:
        return "DATA";
      case DMAResponseType_ACK:
        return "ACK";
      case DMAResponseType_NULL:
        return "NULL";
      default:
        panic("Invalid range for type DMAResponseType");
    }
}

// Code to convert from a string to the enumeration
DMAResponseType
string_to_DMAResponseType(const string& str)
{
    if (str == "DATA") {
        return DMAResponseType_DATA;
    } else if (str == "ACK") {
        return DMAResponseType_ACK;
    } else if (str == "NULL") {
        return DMAResponseType_NULL;
    } else {
        panic("Invalid string conversion for %s, type DMAResponseType", str);
    }
}

// Code to increment an enumeration type
DMAResponseType&
operator++(DMAResponseType& e)
{
    assert(e < DMAResponseType_NUM);
    return e = DMAResponseType(e+1);
}
