/** \file Directory_Event.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __Directory_Event_HH__
#define __Directory_Event_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum Directory_Event
 *  \brief Directory events
 */
enum Directory_Event {
    Directory_Event_FIRST,
    Directory_Event_GETX = Directory_Event_FIRST, /**< A GETX arrives */
    Directory_Event_GETS, /**< A GETS arrives */
    Directory_Event_PUTX, /**< A PUTX arrives */
    Directory_Event_PUTX_NotOwner, /**< A PUTX arrives */
    Directory_Event_DMA_READ, /**< A DMA Read memory request */
    Directory_Event_DMA_WRITE, /**< A DMA Write memory request */
    Directory_Event_Memory_Data, /**< Fetched data from memory arrives */
    Directory_Event_Memory_Ack, /**< Writeback Ack from memory arrives */
    Directory_Event_NUM
};

// Code to convert from a string to the enumeration
Directory_Event string_to_Directory_Event(const std::string& str);

// Code to convert state to a string
std::string Directory_Event_to_string(const Directory_Event& obj);

// Code to increment an enumeration type
Directory_Event &operator++(Directory_Event &e);
std::ostream& operator<<(std::ostream& out, const Directory_Event& obj);

#endif // __Directory_Event_HH__
