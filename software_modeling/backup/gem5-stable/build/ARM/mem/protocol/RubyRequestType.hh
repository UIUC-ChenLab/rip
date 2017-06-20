/** \file RubyRequestType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __RubyRequestType_HH__
#define __RubyRequestType_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum RubyRequestType
 *  \brief ...
 */
enum RubyRequestType {
    RubyRequestType_FIRST,
    RubyRequestType_LD = RubyRequestType_FIRST, /**< Load */
    RubyRequestType_ST, /**< Store */
    RubyRequestType_ATOMIC, /**< Atomic Load/Store */
    RubyRequestType_IFETCH, /**< Instruction fetch */
    RubyRequestType_IO, /**< I/O */
    RubyRequestType_REPLACEMENT, /**< Replacement */
    RubyRequestType_Load_Linked, /**<  */
    RubyRequestType_Store_Conditional, /**<  */
    RubyRequestType_RMW_Read, /**<  */
    RubyRequestType_RMW_Write, /**<  */
    RubyRequestType_Locked_RMW_Read, /**<  */
    RubyRequestType_Locked_RMW_Write, /**<  */
    RubyRequestType_COMMIT, /**< Commit version */
    RubyRequestType_NULL, /**< Invalid request type */
    RubyRequestType_FLUSH, /**< Flush request type */
    RubyRequestType_NUM
};

// Code to convert from a string to the enumeration
RubyRequestType string_to_RubyRequestType(const std::string& str);

// Code to convert state to a string
std::string RubyRequestType_to_string(const RubyRequestType& obj);

// Code to increment an enumeration type
RubyRequestType &operator++(RubyRequestType &e);
std::ostream& operator<<(std::ostream& out, const RubyRequestType& obj);

#endif // __RubyRequestType_HH__
