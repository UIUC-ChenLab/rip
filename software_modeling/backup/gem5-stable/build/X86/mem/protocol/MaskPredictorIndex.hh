/** \file MaskPredictorIndex.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __MaskPredictorIndex_HH__
#define __MaskPredictorIndex_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum MaskPredictorIndex
 *  \brief ...
 */
enum MaskPredictorIndex {
    MaskPredictorIndex_FIRST,
    MaskPredictorIndex_Undefined = MaskPredictorIndex_FIRST, /**< Undefined */
    MaskPredictorIndex_DataBlock, /**< Data Block */
    MaskPredictorIndex_PC, /**< Program Counter */
    MaskPredictorIndex_NUM
};

// Code to convert from a string to the enumeration
MaskPredictorIndex string_to_MaskPredictorIndex(const std::string& str);

// Code to convert state to a string
std::string MaskPredictorIndex_to_string(const MaskPredictorIndex& obj);

// Code to increment an enumeration type
MaskPredictorIndex &operator++(MaskPredictorIndex &e);
std::ostream& operator<<(std::ostream& out, const MaskPredictorIndex& obj);

#endif // __MaskPredictorIndex_HH__
