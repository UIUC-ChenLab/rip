/** \file LinkDirection.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __LinkDirection_HH__
#define __LinkDirection_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum LinkDirection
 *  \brief ...
 */
enum LinkDirection {
    LinkDirection_FIRST,
    LinkDirection_In = LinkDirection_FIRST, /**< Inward link direction */
    LinkDirection_Out, /**< Outward link direction */
    LinkDirection_NUM
};

// Code to convert from a string to the enumeration
LinkDirection string_to_LinkDirection(const std::string& str);

// Code to convert state to a string
std::string LinkDirection_to_string(const LinkDirection& obj);

// Code to increment an enumeration type
LinkDirection &operator++(LinkDirection &e);
std::ostream& operator<<(std::ostream& out, const LinkDirection& obj);

#endif // __LinkDirection_HH__
