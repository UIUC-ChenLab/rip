/** \file AccessType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __AccessType_HH__
#define __AccessType_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum AccessType
 *  \brief ...
 */
enum AccessType {
    AccessType_FIRST,
    AccessType_Read = AccessType_FIRST, /**< Reading from cache */
    AccessType_Write, /**< Writing to cache */
    AccessType_NUM
};

// Code to convert from a string to the enumeration
AccessType string_to_AccessType(const std::string& str);

// Code to convert state to a string
std::string AccessType_to_string(const AccessType& obj);

// Code to increment an enumeration type
AccessType &operator++(AccessType &e);
std::ostream& operator<<(std::ostream& out, const AccessType& obj);

#endif // __AccessType_HH__
