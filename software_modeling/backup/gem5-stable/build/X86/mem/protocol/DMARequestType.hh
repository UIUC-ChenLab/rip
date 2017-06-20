/** \file DMARequestType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __DMARequestType_HH__
#define __DMARequestType_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum DMARequestType
 *  \brief ...
 */
enum DMARequestType {
    DMARequestType_FIRST,
    DMARequestType_READ = DMARequestType_FIRST, /**< Memory Read */
    DMARequestType_WRITE, /**< Memory Write */
    DMARequestType_NULL, /**< Invalid */
    DMARequestType_NUM
};

// Code to convert from a string to the enumeration
DMARequestType string_to_DMARequestType(const std::string& str);

// Code to convert state to a string
std::string DMARequestType_to_string(const DMARequestType& obj);

// Code to increment an enumeration type
DMARequestType &operator++(DMARequestType &e);
std::ostream& operator<<(std::ostream& out, const DMARequestType& obj);

#endif // __DMARequestType_HH__
