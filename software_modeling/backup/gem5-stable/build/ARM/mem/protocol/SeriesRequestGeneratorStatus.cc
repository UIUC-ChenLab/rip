/** \file SeriesRequestGeneratorStatus.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/SeriesRequestGeneratorStatus.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const SeriesRequestGeneratorStatus& obj)
{
    out << SeriesRequestGeneratorStatus_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
SeriesRequestGeneratorStatus_to_string(const SeriesRequestGeneratorStatus& obj)
{
    switch(obj) {
      case SeriesRequestGeneratorStatus_Thinking:
        return "Thinking";
      case SeriesRequestGeneratorStatus_Request_Pending:
        return "Request_Pending";
      default:
        panic("Invalid range for type SeriesRequestGeneratorStatus");
    }
}

// Code to convert from a string to the enumeration
SeriesRequestGeneratorStatus
string_to_SeriesRequestGeneratorStatus(const string& str)
{
    if (str == "Thinking") {
        return SeriesRequestGeneratorStatus_Thinking;
    } else if (str == "Request_Pending") {
        return SeriesRequestGeneratorStatus_Request_Pending;
    } else {
        panic("Invalid string conversion for %s, type SeriesRequestGeneratorStatus", str);
    }
}

// Code to increment an enumeration type
SeriesRequestGeneratorStatus&
operator++(SeriesRequestGeneratorStatus& e)
{
    assert(e < SeriesRequestGeneratorStatus_NUM);
    return e = SeriesRequestGeneratorStatus(e+1);
}
