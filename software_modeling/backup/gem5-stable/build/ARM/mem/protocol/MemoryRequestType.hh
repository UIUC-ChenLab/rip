/** \file MemoryRequestType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __MemoryRequestType_HH__
#define __MemoryRequestType_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum MemoryRequestType
 *  \brief ...
 */
enum MemoryRequestType {
    MemoryRequestType_FIRST,
    MemoryRequestType_MEMORY_READ = MemoryRequestType_FIRST, /**< Read request to memory */
    MemoryRequestType_MEMORY_WB, /**< Write back data to memory */
    MemoryRequestType_MEMORY_DATA, /**< Data read from memory */
    MemoryRequestType_MEMORY_ACK, /**< Write to memory acknowledgement */
    MemoryRequestType_NUM
};

// Code to convert from a string to the enumeration
MemoryRequestType string_to_MemoryRequestType(const std::string& str);

// Code to convert state to a string
std::string MemoryRequestType_to_string(const MemoryRequestType& obj);

// Code to increment an enumeration type
MemoryRequestType &operator++(MemoryRequestType &e);
std::ostream& operator<<(std::ostream& out, const MemoryRequestType& obj);

#endif // __MemoryRequestType_HH__
