/** \file L1Cache_Event.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/L1Cache_Event.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const L1Cache_Event& obj)
{
    out << L1Cache_Event_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
L1Cache_Event_to_string(const L1Cache_Event& obj)
{
    switch(obj) {
      case L1Cache_Event_Load:
        return "Load";
      case L1Cache_Event_Ifetch:
        return "Ifetch";
      case L1Cache_Event_Store:
        return "Store";
      case L1Cache_Event_Data:
        return "Data";
      case L1Cache_Event_Fwd_GETX:
        return "Fwd_GETX";
      case L1Cache_Event_Inv:
        return "Inv";
      case L1Cache_Event_Replacement:
        return "Replacement";
      case L1Cache_Event_Writeback_Ack:
        return "Writeback_Ack";
      case L1Cache_Event_Writeback_Nack:
        return "Writeback_Nack";
      default:
        panic("Invalid range for type L1Cache_Event");
    }
}

// Code to convert from a string to the enumeration
L1Cache_Event
string_to_L1Cache_Event(const string& str)
{
    if (str == "Load") {
        return L1Cache_Event_Load;
    } else if (str == "Ifetch") {
        return L1Cache_Event_Ifetch;
    } else if (str == "Store") {
        return L1Cache_Event_Store;
    } else if (str == "Data") {
        return L1Cache_Event_Data;
    } else if (str == "Fwd_GETX") {
        return L1Cache_Event_Fwd_GETX;
    } else if (str == "Inv") {
        return L1Cache_Event_Inv;
    } else if (str == "Replacement") {
        return L1Cache_Event_Replacement;
    } else if (str == "Writeback_Ack") {
        return L1Cache_Event_Writeback_Ack;
    } else if (str == "Writeback_Nack") {
        return L1Cache_Event_Writeback_Nack;
    } else {
        panic("Invalid string conversion for %s, type L1Cache_Event", str);
    }
}

// Code to increment an enumeration type
L1Cache_Event&
operator++(L1Cache_Event& e)
{
    assert(e < L1Cache_Event_NUM);
    return e = L1Cache_Event(e+1);
}
