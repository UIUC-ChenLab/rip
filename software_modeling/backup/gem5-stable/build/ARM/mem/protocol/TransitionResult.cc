/** \file TransitionResult.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/TransitionResult.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const TransitionResult& obj)
{
    out << TransitionResult_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
TransitionResult_to_string(const TransitionResult& obj)
{
    switch(obj) {
      case TransitionResult_Valid:
        return "Valid";
      case TransitionResult_ResourceStall:
        return "ResourceStall";
      case TransitionResult_ProtocolStall:
        return "ProtocolStall";
      default:
        panic("Invalid range for type TransitionResult");
    }
}

// Code to convert from a string to the enumeration
TransitionResult
string_to_TransitionResult(const string& str)
{
    if (str == "Valid") {
        return TransitionResult_Valid;
    } else if (str == "ResourceStall") {
        return TransitionResult_ResourceStall;
    } else if (str == "ProtocolStall") {
        return TransitionResult_ProtocolStall;
    } else {
        panic("Invalid string conversion for %s, type TransitionResult", str);
    }
}

// Code to increment an enumeration type
TransitionResult&
operator++(TransitionResult& e)
{
    assert(e < TransitionResult_NUM);
    return e = TransitionResult(e+1);
}
