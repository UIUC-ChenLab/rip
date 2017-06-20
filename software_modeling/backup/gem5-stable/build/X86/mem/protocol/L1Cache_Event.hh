/** \file L1Cache_Event.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __L1Cache_Event_HH__
#define __L1Cache_Event_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum L1Cache_Event
 *  \brief Cache events
 */
enum L1Cache_Event {
    L1Cache_Event_FIRST,
    L1Cache_Event_Load = L1Cache_Event_FIRST, /**< Load request from processor */
    L1Cache_Event_Ifetch, /**< Ifetch request from processor */
    L1Cache_Event_Store, /**< Store request from processor */
    L1Cache_Event_Data, /**< Data from network */
    L1Cache_Event_Fwd_GETX, /**< Forward from network */
    L1Cache_Event_Inv, /**< Invalidate request from dir */
    L1Cache_Event_Replacement, /**< Replace a block */
    L1Cache_Event_Writeback_Ack, /**< Ack from the directory for a writeback */
    L1Cache_Event_Writeback_Nack, /**< Nack from the directory for a writeback */
    L1Cache_Event_NUM
};

// Code to convert from a string to the enumeration
L1Cache_Event string_to_L1Cache_Event(const std::string& str);

// Code to convert state to a string
std::string L1Cache_Event_to_string(const L1Cache_Event& obj);

// Code to increment an enumeration type
L1Cache_Event &operator++(L1Cache_Event &e);
std::ostream& operator<<(std::ostream& out, const L1Cache_Event& obj);

#endif // __L1Cache_Event_HH__
