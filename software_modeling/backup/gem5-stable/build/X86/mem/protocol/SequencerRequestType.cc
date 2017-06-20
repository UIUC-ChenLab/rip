/** \file SequencerRequestType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/SequencerRequestType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const SequencerRequestType& obj)
{
    out << SequencerRequestType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
SequencerRequestType_to_string(const SequencerRequestType& obj)
{
    switch(obj) {
      case SequencerRequestType_Default:
        return "Default";
      case SequencerRequestType_LD:
        return "LD";
      case SequencerRequestType_ST:
        return "ST";
      case SequencerRequestType_NULL:
        return "NULL";
      default:
        panic("Invalid range for type SequencerRequestType");
    }
}

// Code to convert from a string to the enumeration
SequencerRequestType
string_to_SequencerRequestType(const string& str)
{
    if (str == "Default") {
        return SequencerRequestType_Default;
    } else if (str == "LD") {
        return SequencerRequestType_LD;
    } else if (str == "ST") {
        return SequencerRequestType_ST;
    } else if (str == "NULL") {
        return SequencerRequestType_NULL;
    } else {
        panic("Invalid string conversion for %s, type SequencerRequestType", str);
    }
}

// Code to increment an enumeration type
SequencerRequestType&
operator++(SequencerRequestType& e)
{
    assert(e < SequencerRequestType_NUM);
    return e = SequencerRequestType(e+1);
}
