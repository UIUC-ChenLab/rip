/** \file AccessPermission.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/AccessPermission.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const AccessPermission& obj)
{
    out << AccessPermission_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
AccessPermission_to_string(const AccessPermission& obj)
{
    switch(obj) {
      case AccessPermission_Read_Only:
        return "Read_Only";
      case AccessPermission_Read_Write:
        return "Read_Write";
      case AccessPermission_Maybe_Stale:
        return "Maybe_Stale";
      case AccessPermission_Backing_Store:
        return "Backing_Store";
      case AccessPermission_Invalid:
        return "Invalid";
      case AccessPermission_NotPresent:
        return "NotPresent";
      case AccessPermission_Busy:
        return "Busy";
      default:
        panic("Invalid range for type AccessPermission");
    }
}

// Code to convert from a string to the enumeration
AccessPermission
string_to_AccessPermission(const string& str)
{
    if (str == "Read_Only") {
        return AccessPermission_Read_Only;
    } else if (str == "Read_Write") {
        return AccessPermission_Read_Write;
    } else if (str == "Maybe_Stale") {
        return AccessPermission_Maybe_Stale;
    } else if (str == "Backing_Store") {
        return AccessPermission_Backing_Store;
    } else if (str == "Invalid") {
        return AccessPermission_Invalid;
    } else if (str == "NotPresent") {
        return AccessPermission_NotPresent;
    } else if (str == "Busy") {
        return AccessPermission_Busy;
    } else {
        panic("Invalid string conversion for %s, type AccessPermission", str);
    }
}

// Code to increment an enumeration type
AccessPermission&
operator++(AccessPermission& e)
{
    assert(e < AccessPermission_NUM);
    return e = AccessPermission(e+1);
}
