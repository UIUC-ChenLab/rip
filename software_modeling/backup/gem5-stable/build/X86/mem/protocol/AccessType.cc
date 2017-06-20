/** \file AccessType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/AccessType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const AccessType& obj)
{
    out << AccessType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
AccessType_to_string(const AccessType& obj)
{
    switch(obj) {
      case AccessType_Read:
        return "Read";
      case AccessType_Write:
        return "Write";
      default:
        panic("Invalid range for type AccessType");
    }
}

// Code to convert from a string to the enumeration
AccessType
string_to_AccessType(const string& str)
{
    if (str == "Read") {
        return AccessType_Read;
    } else if (str == "Write") {
        return AccessType_Write;
    } else {
        panic("Invalid string conversion for %s, type AccessType", str);
    }
}

// Code to increment an enumeration type
AccessType&
operator++(AccessType& e)
{
    assert(e < AccessType_NUM);
    return e = AccessType(e+1);
}
