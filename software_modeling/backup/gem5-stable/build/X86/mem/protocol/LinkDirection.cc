/** \file LinkDirection.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/LinkDirection.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const LinkDirection& obj)
{
    out << LinkDirection_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
LinkDirection_to_string(const LinkDirection& obj)
{
    switch(obj) {
      case LinkDirection_In:
        return "In";
      case LinkDirection_Out:
        return "Out";
      default:
        panic("Invalid range for type LinkDirection");
    }
}

// Code to convert from a string to the enumeration
LinkDirection
string_to_LinkDirection(const string& str)
{
    if (str == "In") {
        return LinkDirection_In;
    } else if (str == "Out") {
        return LinkDirection_Out;
    } else {
        panic("Invalid string conversion for %s, type LinkDirection", str);
    }
}

// Code to increment an enumeration type
LinkDirection&
operator++(LinkDirection& e)
{
    assert(e < LinkDirection_NUM);
    return e = LinkDirection(e+1);
}
