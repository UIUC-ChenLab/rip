/** \file CacheResourceType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/CacheResourceType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const CacheResourceType& obj)
{
    out << CacheResourceType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
CacheResourceType_to_string(const CacheResourceType& obj)
{
    switch(obj) {
      case CacheResourceType_DataArray:
        return "DataArray";
      case CacheResourceType_TagArray:
        return "TagArray";
      default:
        panic("Invalid range for type CacheResourceType");
    }
}

// Code to convert from a string to the enumeration
CacheResourceType
string_to_CacheResourceType(const string& str)
{
    if (str == "DataArray") {
        return CacheResourceType_DataArray;
    } else if (str == "TagArray") {
        return CacheResourceType_TagArray;
    } else {
        panic("Invalid string conversion for %s, type CacheResourceType", str);
    }
}

// Code to increment an enumeration type
CacheResourceType&
operator++(CacheResourceType& e)
{
    assert(e < CacheResourceType_NUM);
    return e = CacheResourceType(e+1);
}
