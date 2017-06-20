/** \file LockStatus.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/LockStatus.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const LockStatus& obj)
{
    out << LockStatus_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
LockStatus_to_string(const LockStatus& obj)
{
    switch(obj) {
      case LockStatus_Unlocked:
        return "Unlocked";
      case LockStatus_Locked:
        return "Locked";
      default:
        panic("Invalid range for type LockStatus");
    }
}

// Code to convert from a string to the enumeration
LockStatus
string_to_LockStatus(const string& str)
{
    if (str == "Unlocked") {
        return LockStatus_Unlocked;
    } else if (str == "Locked") {
        return LockStatus_Locked;
    } else {
        panic("Invalid string conversion for %s, type LockStatus", str);
    }
}

// Code to increment an enumeration type
LockStatus&
operator++(LockStatus& e)
{
    assert(e < LockStatus_NUM);
    return e = LockStatus(e+1);
}
