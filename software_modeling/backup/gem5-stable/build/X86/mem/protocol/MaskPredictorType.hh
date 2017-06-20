/** \file MaskPredictorType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __MaskPredictorType_HH__
#define __MaskPredictorType_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum MaskPredictorType
 *  \brief ...
 */
enum MaskPredictorType {
    MaskPredictorType_FIRST,
    MaskPredictorType_Undefined = MaskPredictorType_FIRST, /**< Undefined */
    MaskPredictorType_AlwaysUnicast, /**< AlwaysUnicast */
    MaskPredictorType_TokenD, /**< TokenD */
    MaskPredictorType_AlwaysBroadcast, /**< AlwaysBroadcast */
    MaskPredictorType_TokenB, /**< TokenB */
    MaskPredictorType_TokenNull, /**< TokenNull */
    MaskPredictorType_Random, /**< Random */
    MaskPredictorType_Pairwise, /**< Pairwise */
    MaskPredictorType_Owner, /**< Owner */
    MaskPredictorType_BroadcastIfShared, /**< Broadcast-If-Shared */
    MaskPredictorType_BroadcastCounter, /**< Broadcast Counter */
    MaskPredictorType_Group, /**< Group */
    MaskPredictorType_Counter, /**< Counter */
    MaskPredictorType_StickySpatial, /**< StickySpatial */
    MaskPredictorType_OwnerBroadcast, /**< Owner/Broadcast Hybrid */
    MaskPredictorType_OwnerGroup, /**< Owner/Group Hybrid */
    MaskPredictorType_OwnerBroadcastMod, /**< Owner/Broadcast Hybrid-Mod */
    MaskPredictorType_OwnerGroupMod, /**< Owner/Group Hybrid-Mod */
    MaskPredictorType_LastNMasks, /**< Last N Masks */
    MaskPredictorType_BandwidthAdaptive, /**< Bandwidth Adaptive */
    MaskPredictorType_NUM
};

// Code to convert from a string to the enumeration
MaskPredictorType string_to_MaskPredictorType(const std::string& str);

// Code to convert state to a string
std::string MaskPredictorType_to_string(const MaskPredictorType& obj);

// Code to increment an enumeration type
MaskPredictorType &operator++(MaskPredictorType &e);
std::ostream& operator<<(std::ostream& out, const MaskPredictorType& obj);

#endif // __MaskPredictorType_HH__
