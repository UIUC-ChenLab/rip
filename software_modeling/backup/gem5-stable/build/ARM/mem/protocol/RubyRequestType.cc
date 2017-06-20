/** \file RubyRequestType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/RubyRequestType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const RubyRequestType& obj)
{
    out << RubyRequestType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
RubyRequestType_to_string(const RubyRequestType& obj)
{
    switch(obj) {
      case RubyRequestType_LD:
        return "LD";
      case RubyRequestType_ST:
        return "ST";
      case RubyRequestType_ATOMIC:
        return "ATOMIC";
      case RubyRequestType_IFETCH:
        return "IFETCH";
      case RubyRequestType_IO:
        return "IO";
      case RubyRequestType_REPLACEMENT:
        return "REPLACEMENT";
      case RubyRequestType_Load_Linked:
        return "Load_Linked";
      case RubyRequestType_Store_Conditional:
        return "Store_Conditional";
      case RubyRequestType_RMW_Read:
        return "RMW_Read";
      case RubyRequestType_RMW_Write:
        return "RMW_Write";
      case RubyRequestType_Locked_RMW_Read:
        return "Locked_RMW_Read";
      case RubyRequestType_Locked_RMW_Write:
        return "Locked_RMW_Write";
      case RubyRequestType_COMMIT:
        return "COMMIT";
      case RubyRequestType_NULL:
        return "NULL";
      case RubyRequestType_FLUSH:
        return "FLUSH";
      default:
        panic("Invalid range for type RubyRequestType");
    }
}

// Code to convert from a string to the enumeration
RubyRequestType
string_to_RubyRequestType(const string& str)
{
    if (str == "LD") {
        return RubyRequestType_LD;
    } else if (str == "ST") {
        return RubyRequestType_ST;
    } else if (str == "ATOMIC") {
        return RubyRequestType_ATOMIC;
    } else if (str == "IFETCH") {
        return RubyRequestType_IFETCH;
    } else if (str == "IO") {
        return RubyRequestType_IO;
    } else if (str == "REPLACEMENT") {
        return RubyRequestType_REPLACEMENT;
    } else if (str == "Load_Linked") {
        return RubyRequestType_Load_Linked;
    } else if (str == "Store_Conditional") {
        return RubyRequestType_Store_Conditional;
    } else if (str == "RMW_Read") {
        return RubyRequestType_RMW_Read;
    } else if (str == "RMW_Write") {
        return RubyRequestType_RMW_Write;
    } else if (str == "Locked_RMW_Read") {
        return RubyRequestType_Locked_RMW_Read;
    } else if (str == "Locked_RMW_Write") {
        return RubyRequestType_Locked_RMW_Write;
    } else if (str == "COMMIT") {
        return RubyRequestType_COMMIT;
    } else if (str == "NULL") {
        return RubyRequestType_NULL;
    } else if (str == "FLUSH") {
        return RubyRequestType_FLUSH;
    } else {
        panic("Invalid string conversion for %s, type RubyRequestType", str);
    }
}

// Code to increment an enumeration type
RubyRequestType&
operator++(RubyRequestType& e)
{
    assert(e < RubyRequestType_NUM);
    return e = RubyRequestType(e+1);
}
