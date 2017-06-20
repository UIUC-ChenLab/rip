/** \file MaskPredictorTraining.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/MaskPredictorTraining.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const MaskPredictorTraining& obj)
{
    out << MaskPredictorTraining_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
MaskPredictorTraining_to_string(const MaskPredictorTraining& obj)
{
    switch(obj) {
      case MaskPredictorTraining_Undefined:
        return "Undefined";
      case MaskPredictorTraining_None:
        return "None";
      case MaskPredictorTraining_Implicit:
        return "Implicit";
      case MaskPredictorTraining_Explicit:
        return "Explicit";
      case MaskPredictorTraining_Both:
        return "Both";
      default:
        panic("Invalid range for type MaskPredictorTraining");
    }
}

// Code to convert from a string to the enumeration
MaskPredictorTraining
string_to_MaskPredictorTraining(const string& str)
{
    if (str == "Undefined") {
        return MaskPredictorTraining_Undefined;
    } else if (str == "None") {
        return MaskPredictorTraining_None;
    } else if (str == "Implicit") {
        return MaskPredictorTraining_Implicit;
    } else if (str == "Explicit") {
        return MaskPredictorTraining_Explicit;
    } else if (str == "Both") {
        return MaskPredictorTraining_Both;
    } else {
        panic("Invalid string conversion for %s, type MaskPredictorTraining", str);
    }
}

// Code to increment an enumeration type
MaskPredictorTraining&
operator++(MaskPredictorTraining& e)
{
    assert(e < MaskPredictorTraining_NUM);
    return e = MaskPredictorTraining(e+1);
}
