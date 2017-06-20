/** \file RubyAccessMode.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __RubyAccessMode_HH__
#define __RubyAccessMode_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum RubyAccessMode
 *  \brief ...
 */
enum RubyAccessMode {
    RubyAccessMode_FIRST,
    RubyAccessMode_Supervisor = RubyAccessMode_FIRST, /**< Supervisor mode */
    RubyAccessMode_User, /**< User mode */
    RubyAccessMode_Device, /**< Device mode */
    RubyAccessMode_NUM
};

// Code to convert from a string to the enumeration
RubyAccessMode string_to_RubyAccessMode(const std::string& str);

// Code to convert state to a string
std::string RubyAccessMode_to_string(const RubyAccessMode& obj);

// Code to increment an enumeration type
RubyAccessMode &operator++(RubyAccessMode &e);
std::ostream& operator<<(std::ostream& out, const RubyAccessMode& obj);

#endif // __RubyAccessMode_HH__
