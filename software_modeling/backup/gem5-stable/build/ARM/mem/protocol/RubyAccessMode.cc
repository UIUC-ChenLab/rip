/** \file RubyAccessMode.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/RubyAccessMode.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const RubyAccessMode& obj)
{
    out << RubyAccessMode_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
RubyAccessMode_to_string(const RubyAccessMode& obj)
{
    switch(obj) {
      case RubyAccessMode_Supervisor:
        return "Supervisor";
      case RubyAccessMode_User:
        return "User";
      case RubyAccessMode_Device:
        return "Device";
      default:
        panic("Invalid range for type RubyAccessMode");
    }
}

// Code to convert from a string to the enumeration
RubyAccessMode
string_to_RubyAccessMode(const string& str)
{
    if (str == "Supervisor") {
        return RubyAccessMode_Supervisor;
    } else if (str == "User") {
        return RubyAccessMode_User;
    } else if (str == "Device") {
        return RubyAccessMode_Device;
    } else {
        panic("Invalid string conversion for %s, type RubyAccessMode", str);
    }
}

// Code to increment an enumeration type
RubyAccessMode&
operator++(RubyAccessMode& e)
{
    assert(e < RubyAccessMode_NUM);
    return e = RubyAccessMode(e+1);
}
