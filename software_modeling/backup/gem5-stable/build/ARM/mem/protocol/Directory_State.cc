/** \file Directory_State.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/Directory_State.hh"

using namespace std;

// Code to convert the current state to an access permission
AccessPermission Directory_State_to_permission(const Directory_State& obj)
{
    switch(obj) {
      case Directory_State_I:
        return AccessPermission_Read_Write;
      case Directory_State_M:
        return AccessPermission_Invalid;
      case Directory_State_M_DRD:
        return AccessPermission_Busy;
      case Directory_State_M_DWR:
        return AccessPermission_Busy;
      case Directory_State_M_DWRI:
        return AccessPermission_Busy;
      case Directory_State_M_DRDI:
        return AccessPermission_Busy;
      case Directory_State_IM:
        return AccessPermission_Busy;
      case Directory_State_MI:
        return AccessPermission_Busy;
      case Directory_State_ID:
        return AccessPermission_Busy;
      case Directory_State_ID_W:
        return AccessPermission_Busy;
      default:
        panic("Unknown state access permission converstion for Directory_State");
    }
}

// Code for output operator
ostream&
operator<<(ostream& out, const Directory_State& obj)
{
    out << Directory_State_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
Directory_State_to_string(const Directory_State& obj)
{
    switch(obj) {
      case Directory_State_I:
        return "I";
      case Directory_State_M:
        return "M";
      case Directory_State_M_DRD:
        return "M_DRD";
      case Directory_State_M_DWR:
        return "M_DWR";
      case Directory_State_M_DWRI:
        return "M_DWRI";
      case Directory_State_M_DRDI:
        return "M_DRDI";
      case Directory_State_IM:
        return "IM";
      case Directory_State_MI:
        return "MI";
      case Directory_State_ID:
        return "ID";
      case Directory_State_ID_W:
        return "ID_W";
      default:
        panic("Invalid range for type Directory_State");
    }
}

// Code to convert from a string to the enumeration
Directory_State
string_to_Directory_State(const string& str)
{
    if (str == "I") {
        return Directory_State_I;
    } else if (str == "M") {
        return Directory_State_M;
    } else if (str == "M_DRD") {
        return Directory_State_M_DRD;
    } else if (str == "M_DWR") {
        return Directory_State_M_DWR;
    } else if (str == "M_DWRI") {
        return Directory_State_M_DWRI;
    } else if (str == "M_DRDI") {
        return Directory_State_M_DRDI;
    } else if (str == "IM") {
        return Directory_State_IM;
    } else if (str == "MI") {
        return Directory_State_MI;
    } else if (str == "ID") {
        return Directory_State_ID;
    } else if (str == "ID_W") {
        return Directory_State_ID_W;
    } else {
        panic("Invalid string conversion for %s, type Directory_State", str);
    }
}

// Code to increment an enumeration type
Directory_State&
operator++(Directory_State& e)
{
    assert(e < Directory_State_NUM);
    return e = Directory_State(e+1);
}
