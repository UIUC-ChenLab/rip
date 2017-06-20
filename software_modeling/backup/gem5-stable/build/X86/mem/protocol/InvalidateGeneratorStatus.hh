/** \file InvalidateGeneratorStatus.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __InvalidateGeneratorStatus_HH__
#define __InvalidateGeneratorStatus_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum InvalidateGeneratorStatus
 *  \brief ...
 */
enum InvalidateGeneratorStatus {
    InvalidateGeneratorStatus_FIRST,
    InvalidateGeneratorStatus_Load_Waiting = InvalidateGeneratorStatus_FIRST, /**< Load waiting to be issued */
    InvalidateGeneratorStatus_Load_Pending, /**< Load issued */
    InvalidateGeneratorStatus_Inv_Waiting, /**< Store (invalidate) waiting to be issued */
    InvalidateGeneratorStatus_Inv_Pending, /**< Store (invalidate) issued */
    InvalidateGeneratorStatus_NUM
};

// Code to convert from a string to the enumeration
InvalidateGeneratorStatus string_to_InvalidateGeneratorStatus(const std::string& str);

// Code to convert state to a string
std::string InvalidateGeneratorStatus_to_string(const InvalidateGeneratorStatus& obj);

// Code to increment an enumeration type
InvalidateGeneratorStatus &operator++(InvalidateGeneratorStatus &e);
std::ostream& operator<<(std::ostream& out, const InvalidateGeneratorStatus& obj);

#endif // __InvalidateGeneratorStatus_HH__
