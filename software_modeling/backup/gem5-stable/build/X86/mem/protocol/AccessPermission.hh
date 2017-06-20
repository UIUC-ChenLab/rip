/** \file AccessPermission.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __AccessPermission_HH__
#define __AccessPermission_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum AccessPermission
 *  \brief ...
 */
enum AccessPermission {
    AccessPermission_FIRST,
    AccessPermission_Read_Only = AccessPermission_FIRST, /**< block is Read Only (modulo functional writes) */
    AccessPermission_Read_Write, /**< block is Read/Write */
    AccessPermission_Maybe_Stale, /**< block can be stale or revalidated by a dataless PUT */
    AccessPermission_Backing_Store, /**< for memory in Broadcast/Snoop protocols */
    AccessPermission_Invalid, /**< block is in an Invalid base state */
    AccessPermission_NotPresent, /**< block is NotPresent */
    AccessPermission_Busy, /**< block is in a transient state, currently invalid */
    AccessPermission_NUM
};

// Code to convert from a string to the enumeration
AccessPermission string_to_AccessPermission(const std::string& str);

// Code to convert state to a string
std::string AccessPermission_to_string(const AccessPermission& obj);

// Code to increment an enumeration type
AccessPermission &operator++(AccessPermission &e);
std::ostream& operator<<(std::ostream& out, const AccessPermission& obj);

#endif // __AccessPermission_HH__
