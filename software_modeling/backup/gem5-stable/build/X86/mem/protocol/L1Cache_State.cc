/** \file L1Cache_State.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/L1Cache_State.hh"

using namespace std;

// Code to convert the current state to an access permission
AccessPermission L1Cache_State_to_permission(const L1Cache_State& obj)
{
    switch(obj) {
      case L1Cache_State_I:
        return AccessPermission_Invalid;
      case L1Cache_State_II:
        return AccessPermission_Busy;
      case L1Cache_State_M:
        return AccessPermission_Read_Write;
      case L1Cache_State_MI:
        return AccessPermission_Busy;
      case L1Cache_State_MII:
        return AccessPermission_Busy;
      case L1Cache_State_IS:
        return AccessPermission_Busy;
      case L1Cache_State_IM:
        return AccessPermission_Busy;
      default:
        panic("Unknown state access permission converstion for L1Cache_State");
    }
}

// Code for output operator
ostream&
operator<<(ostream& out, const L1Cache_State& obj)
{
    out << L1Cache_State_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
L1Cache_State_to_string(const L1Cache_State& obj)
{
    switch(obj) {
      case L1Cache_State_I:
        return "I";
      case L1Cache_State_II:
        return "II";
      case L1Cache_State_M:
        return "M";
      case L1Cache_State_MI:
        return "MI";
      case L1Cache_State_MII:
        return "MII";
      case L1Cache_State_IS:
        return "IS";
      case L1Cache_State_IM:
        return "IM";
      default:
        panic("Invalid range for type L1Cache_State");
    }
}

// Code to convert from a string to the enumeration
L1Cache_State
string_to_L1Cache_State(const string& str)
{
    if (str == "I") {
        return L1Cache_State_I;
    } else if (str == "II") {
        return L1Cache_State_II;
    } else if (str == "M") {
        return L1Cache_State_M;
    } else if (str == "MI") {
        return L1Cache_State_MI;
    } else if (str == "MII") {
        return L1Cache_State_MII;
    } else if (str == "IS") {
        return L1Cache_State_IS;
    } else if (str == "IM") {
        return L1Cache_State_IM;
    } else {
        panic("Invalid string conversion for %s, type L1Cache_State", str);
    }
}

// Code to increment an enumeration type
L1Cache_State&
operator++(L1Cache_State& e)
{
    assert(e < L1Cache_State_NUM);
    return e = L1Cache_State(e+1);
}
