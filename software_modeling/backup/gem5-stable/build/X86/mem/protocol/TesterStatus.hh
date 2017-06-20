/** \file TesterStatus.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __TesterStatus_HH__
#define __TesterStatus_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum TesterStatus
 *  \brief ...
 */
enum TesterStatus {
    TesterStatus_FIRST,
    TesterStatus_Idle = TesterStatus_FIRST, /**< Idle */
    TesterStatus_Action_Pending, /**< Action Pending */
    TesterStatus_Ready, /**< Ready */
    TesterStatus_Check_Pending, /**< Check Pending */
    TesterStatus_NUM
};

// Code to convert from a string to the enumeration
TesterStatus string_to_TesterStatus(const std::string& str);

// Code to convert state to a string
std::string TesterStatus_to_string(const TesterStatus& obj);

// Code to increment an enumeration type
TesterStatus &operator++(TesterStatus &e);
std::ostream& operator<<(std::ostream& out, const TesterStatus& obj);

#endif // __TesterStatus_HH__
