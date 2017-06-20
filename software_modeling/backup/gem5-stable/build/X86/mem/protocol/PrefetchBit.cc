/** \file PrefetchBit.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/PrefetchBit.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const PrefetchBit& obj)
{
    out << PrefetchBit_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
PrefetchBit_to_string(const PrefetchBit& obj)
{
    switch(obj) {
      case PrefetchBit_No:
        return "No";
      case PrefetchBit_Yes:
        return "Yes";
      case PrefetchBit_L1_HW:
        return "L1_HW";
      case PrefetchBit_L2_HW:
        return "L2_HW";
      default:
        panic("Invalid range for type PrefetchBit");
    }
}

// Code to convert from a string to the enumeration
PrefetchBit
string_to_PrefetchBit(const string& str)
{
    if (str == "No") {
        return PrefetchBit_No;
    } else if (str == "Yes") {
        return PrefetchBit_Yes;
    } else if (str == "L1_HW") {
        return PrefetchBit_L1_HW;
    } else if (str == "L2_HW") {
        return PrefetchBit_L2_HW;
    } else {
        panic("Invalid string conversion for %s, type PrefetchBit", str);
    }
}

// Code to increment an enumeration type
PrefetchBit&
operator++(PrefetchBit& e)
{
    assert(e < PrefetchBit_NUM);
    return e = PrefetchBit(e+1);
}
