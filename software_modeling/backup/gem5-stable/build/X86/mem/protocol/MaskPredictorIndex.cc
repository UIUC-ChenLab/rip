/** \file MaskPredictorIndex.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/MaskPredictorIndex.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const MaskPredictorIndex& obj)
{
    out << MaskPredictorIndex_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
MaskPredictorIndex_to_string(const MaskPredictorIndex& obj)
{
    switch(obj) {
      case MaskPredictorIndex_Undefined:
        return "Undefined";
      case MaskPredictorIndex_DataBlock:
        return "DataBlock";
      case MaskPredictorIndex_PC:
        return "PC";
      default:
        panic("Invalid range for type MaskPredictorIndex");
    }
}

// Code to convert from a string to the enumeration
MaskPredictorIndex
string_to_MaskPredictorIndex(const string& str)
{
    if (str == "Undefined") {
        return MaskPredictorIndex_Undefined;
    } else if (str == "DataBlock") {
        return MaskPredictorIndex_DataBlock;
    } else if (str == "PC") {
        return MaskPredictorIndex_PC;
    } else {
        panic("Invalid string conversion for %s, type MaskPredictorIndex", str);
    }
}

// Code to increment an enumeration type
MaskPredictorIndex&
operator++(MaskPredictorIndex& e)
{
    assert(e < MaskPredictorIndex_NUM);
    return e = MaskPredictorIndex(e+1);
}
