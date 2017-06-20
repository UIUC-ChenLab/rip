/** \file MachineType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __MachineType_HH__
#define __MachineType_HH__

#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/ruby/common/Address.hh"
struct MachineID;

// Class definition
/** \enum MachineType
 *  \brief No description avaliable
 */
enum MachineType {
    MachineType_FIRST,
    MachineType_L1Cache = MachineType_FIRST, /**< No description avaliable */
    MachineType_Directory, /**< No description avaliable */
    MachineType_DMA, /**< No description avaliable */
    MachineType_NUM
};

// Code to convert from a string to the enumeration
MachineType string_to_MachineType(const std::string& str);

// Code to convert state to a string
std::string MachineType_to_string(const MachineType& obj);

// Code to increment an enumeration type
MachineType &operator++(MachineType &e);
int MachineType_base_level(const MachineType& obj);
MachineType MachineType_from_base_level(int);
int MachineType_base_number(const MachineType& obj);
int MachineType_base_count(const MachineType& obj);

MachineID getL1CacheMachineID(NodeID RubyNode);

MachineID getDirectoryMachineID(NodeID RubyNode);
MachineID map_Address_to_DMA(const Address &addr);

MachineID getDMAMachineID(NodeID RubyNode);
std::ostream& operator<<(std::ostream& out, const MachineType& obj);

#endif // __MachineType_HH__
