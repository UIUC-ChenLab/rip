/** \file SequencerStatus.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/SequencerStatus.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const SequencerStatus& obj)
{
    out << SequencerStatus_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
SequencerStatus_to_string(const SequencerStatus& obj)
{
    switch(obj) {
      case SequencerStatus_Idle:
        return "Idle";
      case SequencerStatus_Pending:
        return "Pending";
      default:
        panic("Invalid range for type SequencerStatus");
    }
}

// Code to convert from a string to the enumeration
SequencerStatus
string_to_SequencerStatus(const string& str)
{
    if (str == "Idle") {
        return SequencerStatus_Idle;
    } else if (str == "Pending") {
        return SequencerStatus_Pending;
    } else {
        panic("Invalid string conversion for %s, type SequencerStatus", str);
    }
}

// Code to increment an enumeration type
SequencerStatus&
operator++(SequencerStatus& e)
{
    assert(e < SequencerStatus_NUM);
    return e = SequencerStatus(e+1);
}
