/** \file DMA_State.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/DMA_State.hh"

using namespace std;

// Code to convert the current state to an access permission
AccessPermission DMA_State_to_permission(const DMA_State& obj)
{
    switch(obj) {
      case DMA_State_READY:
        return AccessPermission_Invalid;
      case DMA_State_BUSY_RD:
        return AccessPermission_Busy;
      case DMA_State_BUSY_WR:
        return AccessPermission_Busy;
      default:
        panic("Unknown state access permission converstion for DMA_State");
    }
}

// Code for output operator
ostream&
operator<<(ostream& out, const DMA_State& obj)
{
    out << DMA_State_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
DMA_State_to_string(const DMA_State& obj)
{
    switch(obj) {
      case DMA_State_READY:
        return "READY";
      case DMA_State_BUSY_RD:
        return "BUSY_RD";
      case DMA_State_BUSY_WR:
        return "BUSY_WR";
      default:
        panic("Invalid range for type DMA_State");
    }
}

// Code to convert from a string to the enumeration
DMA_State
string_to_DMA_State(const string& str)
{
    if (str == "READY") {
        return DMA_State_READY;
    } else if (str == "BUSY_RD") {
        return DMA_State_BUSY_RD;
    } else if (str == "BUSY_WR") {
        return DMA_State_BUSY_WR;
    } else {
        panic("Invalid string conversion for %s, type DMA_State", str);
    }
}

// Code to increment an enumeration type
DMA_State&
operator++(DMA_State& e)
{
    assert(e < DMA_State_NUM);
    return e = DMA_State(e+1);
}
