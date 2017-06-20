/** \file DMA_Event.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/DMA_Event.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const DMA_Event& obj)
{
    out << DMA_Event_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
DMA_Event_to_string(const DMA_Event& obj)
{
    switch(obj) {
      case DMA_Event_ReadRequest:
        return "ReadRequest";
      case DMA_Event_WriteRequest:
        return "WriteRequest";
      case DMA_Event_Data:
        return "Data";
      case DMA_Event_Ack:
        return "Ack";
      default:
        panic("Invalid range for type DMA_Event");
    }
}

// Code to convert from a string to the enumeration
DMA_Event
string_to_DMA_Event(const string& str)
{
    if (str == "ReadRequest") {
        return DMA_Event_ReadRequest;
    } else if (str == "WriteRequest") {
        return DMA_Event_WriteRequest;
    } else if (str == "Data") {
        return DMA_Event_Data;
    } else if (str == "Ack") {
        return DMA_Event_Ack;
    } else {
        panic("Invalid string conversion for %s, type DMA_Event", str);
    }
}

// Code to increment an enumeration type
DMA_Event&
operator++(DMA_Event& e)
{
    assert(e < DMA_Event_NUM);
    return e = DMA_Event(e+1);
}
