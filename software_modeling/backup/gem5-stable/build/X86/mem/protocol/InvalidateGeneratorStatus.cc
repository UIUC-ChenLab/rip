/** \file InvalidateGeneratorStatus.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/InvalidateGeneratorStatus.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const InvalidateGeneratorStatus& obj)
{
    out << InvalidateGeneratorStatus_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
InvalidateGeneratorStatus_to_string(const InvalidateGeneratorStatus& obj)
{
    switch(obj) {
      case InvalidateGeneratorStatus_Load_Waiting:
        return "Load_Waiting";
      case InvalidateGeneratorStatus_Load_Pending:
        return "Load_Pending";
      case InvalidateGeneratorStatus_Inv_Waiting:
        return "Inv_Waiting";
      case InvalidateGeneratorStatus_Inv_Pending:
        return "Inv_Pending";
      default:
        panic("Invalid range for type InvalidateGeneratorStatus");
    }
}

// Code to convert from a string to the enumeration
InvalidateGeneratorStatus
string_to_InvalidateGeneratorStatus(const string& str)
{
    if (str == "Load_Waiting") {
        return InvalidateGeneratorStatus_Load_Waiting;
    } else if (str == "Load_Pending") {
        return InvalidateGeneratorStatus_Load_Pending;
    } else if (str == "Inv_Waiting") {
        return InvalidateGeneratorStatus_Inv_Waiting;
    } else if (str == "Inv_Pending") {
        return InvalidateGeneratorStatus_Inv_Pending;
    } else {
        panic("Invalid string conversion for %s, type InvalidateGeneratorStatus", str);
    }
}

// Code to increment an enumeration type
InvalidateGeneratorStatus&
operator++(InvalidateGeneratorStatus& e)
{
    assert(e < InvalidateGeneratorStatus_NUM);
    return e = InvalidateGeneratorStatus(e+1);
}
