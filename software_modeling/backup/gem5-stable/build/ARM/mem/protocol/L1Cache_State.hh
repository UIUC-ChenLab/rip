/** \file L1Cache_State.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __L1Cache_State_HH__
#define __L1Cache_State_HH__

#include <iostream>
#include <string>

#include "mem/protocol/AccessPermission.hh"

// Class definition
/** \enum L1Cache_State
 *  \brief Cache states
 */
enum L1Cache_State {
    L1Cache_State_FIRST,
    L1Cache_State_I = L1Cache_State_FIRST, /**< Not Present/Invalid */
    L1Cache_State_II, /**< Not Present/Invalid, issued PUT */
    L1Cache_State_M, /**< Modified */
    L1Cache_State_MI, /**< Modified, issued PUT */
    L1Cache_State_MII, /**< Modified, issued PUTX, received nack */
    L1Cache_State_IS, /**< Issued request for LOAD/IFETCH */
    L1Cache_State_IM, /**< Issued request for STORE/ATOMIC */
    L1Cache_State_NUM
};

// Code to convert from a string to the enumeration
L1Cache_State string_to_L1Cache_State(const std::string& str);

// Code to convert state to a string
std::string L1Cache_State_to_string(const L1Cache_State& obj);

// Code to increment an enumeration type
L1Cache_State &operator++(L1Cache_State &e);

// Code to convert the current state to an access permission
AccessPermission L1Cache_State_to_permission(const L1Cache_State& obj);

std::ostream& operator<<(std::ostream& out, const L1Cache_State& obj);

#endif // __L1Cache_State_HH__
