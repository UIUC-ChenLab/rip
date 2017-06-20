/** \file DMASequencerRequestType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/DMASequencerRequestType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const DMASequencerRequestType& obj)
{
    out << DMASequencerRequestType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
DMASequencerRequestType_to_string(const DMASequencerRequestType& obj)
{
    switch(obj) {
      case DMASequencerRequestType_Default:
        return "Default";
      default:
        panic("Invalid range for type DMASequencerRequestType");
    }
}

// Code to convert from a string to the enumeration
DMASequencerRequestType
string_to_DMASequencerRequestType(const string& str)
{
    if (str == "Default") {
        return DMASequencerRequestType_Default;
    } else {
        panic("Invalid string conversion for %s, type DMASequencerRequestType", str);
    }
}

// Code to increment an enumeration type
DMASequencerRequestType&
operator++(DMASequencerRequestType& e)
{
    assert(e < DMASequencerRequestType_NUM);
    return e = DMASequencerRequestType(e+1);
}
