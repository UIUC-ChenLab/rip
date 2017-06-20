/** \file MaskPredictorType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/MaskPredictorType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const MaskPredictorType& obj)
{
    out << MaskPredictorType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
MaskPredictorType_to_string(const MaskPredictorType& obj)
{
    switch(obj) {
      case MaskPredictorType_Undefined:
        return "Undefined";
      case MaskPredictorType_AlwaysUnicast:
        return "AlwaysUnicast";
      case MaskPredictorType_TokenD:
        return "TokenD";
      case MaskPredictorType_AlwaysBroadcast:
        return "AlwaysBroadcast";
      case MaskPredictorType_TokenB:
        return "TokenB";
      case MaskPredictorType_TokenNull:
        return "TokenNull";
      case MaskPredictorType_Random:
        return "Random";
      case MaskPredictorType_Pairwise:
        return "Pairwise";
      case MaskPredictorType_Owner:
        return "Owner";
      case MaskPredictorType_BroadcastIfShared:
        return "BroadcastIfShared";
      case MaskPredictorType_BroadcastCounter:
        return "BroadcastCounter";
      case MaskPredictorType_Group:
        return "Group";
      case MaskPredictorType_Counter:
        return "Counter";
      case MaskPredictorType_StickySpatial:
        return "StickySpatial";
      case MaskPredictorType_OwnerBroadcast:
        return "OwnerBroadcast";
      case MaskPredictorType_OwnerGroup:
        return "OwnerGroup";
      case MaskPredictorType_OwnerBroadcastMod:
        return "OwnerBroadcastMod";
      case MaskPredictorType_OwnerGroupMod:
        return "OwnerGroupMod";
      case MaskPredictorType_LastNMasks:
        return "LastNMasks";
      case MaskPredictorType_BandwidthAdaptive:
        return "BandwidthAdaptive";
      default:
        panic("Invalid range for type MaskPredictorType");
    }
}

// Code to convert from a string to the enumeration
MaskPredictorType
string_to_MaskPredictorType(const string& str)
{
    if (str == "Undefined") {
        return MaskPredictorType_Undefined;
    } else if (str == "AlwaysUnicast") {
        return MaskPredictorType_AlwaysUnicast;
    } else if (str == "TokenD") {
        return MaskPredictorType_TokenD;
    } else if (str == "AlwaysBroadcast") {
        return MaskPredictorType_AlwaysBroadcast;
    } else if (str == "TokenB") {
        return MaskPredictorType_TokenB;
    } else if (str == "TokenNull") {
        return MaskPredictorType_TokenNull;
    } else if (str == "Random") {
        return MaskPredictorType_Random;
    } else if (str == "Pairwise") {
        return MaskPredictorType_Pairwise;
    } else if (str == "Owner") {
        return MaskPredictorType_Owner;
    } else if (str == "BroadcastIfShared") {
        return MaskPredictorType_BroadcastIfShared;
    } else if (str == "BroadcastCounter") {
        return MaskPredictorType_BroadcastCounter;
    } else if (str == "Group") {
        return MaskPredictorType_Group;
    } else if (str == "Counter") {
        return MaskPredictorType_Counter;
    } else if (str == "StickySpatial") {
        return MaskPredictorType_StickySpatial;
    } else if (str == "OwnerBroadcast") {
        return MaskPredictorType_OwnerBroadcast;
    } else if (str == "OwnerGroup") {
        return MaskPredictorType_OwnerGroup;
    } else if (str == "OwnerBroadcastMod") {
        return MaskPredictorType_OwnerBroadcastMod;
    } else if (str == "OwnerGroupMod") {
        return MaskPredictorType_OwnerGroupMod;
    } else if (str == "LastNMasks") {
        return MaskPredictorType_LastNMasks;
    } else if (str == "BandwidthAdaptive") {
        return MaskPredictorType_BandwidthAdaptive;
    } else {
        panic("Invalid string conversion for %s, type MaskPredictorType", str);
    }
}

// Code to increment an enumeration type
MaskPredictorType&
operator++(MaskPredictorType& e)
{
    assert(e < MaskPredictorType_NUM);
    return e = MaskPredictorType(e+1);
}
