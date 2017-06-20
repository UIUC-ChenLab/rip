/** \file TesterStatus.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/TesterStatus.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const TesterStatus& obj)
{
    out << TesterStatus_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
TesterStatus_to_string(const TesterStatus& obj)
{
    switch(obj) {
      case TesterStatus_Idle:
        return "Idle";
      case TesterStatus_Action_Pending:
        return "Action_Pending";
      case TesterStatus_Ready:
        return "Ready";
      case TesterStatus_Check_Pending:
        return "Check_Pending";
      default:
        panic("Invalid range for type TesterStatus");
    }
}

// Code to convert from a string to the enumeration
TesterStatus
string_to_TesterStatus(const string& str)
{
    if (str == "Idle") {
        return TesterStatus_Idle;
    } else if (str == "Action_Pending") {
        return TesterStatus_Action_Pending;
    } else if (str == "Ready") {
        return TesterStatus_Ready;
    } else if (str == "Check_Pending") {
        return TesterStatus_Check_Pending;
    } else {
        panic("Invalid string conversion for %s, type TesterStatus", str);
    }
}

// Code to increment an enumeration type
TesterStatus&
operator++(TesterStatus& e)
{
    assert(e < TesterStatus_NUM);
    return e = TesterStatus(e+1);
}
