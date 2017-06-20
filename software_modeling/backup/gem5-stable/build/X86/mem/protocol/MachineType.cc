/** \file MachineType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/MachineType.hh"

using namespace std;

#include "mem/protocol/L1Cache_Controller.hh"
#include "mem/protocol/Directory_Controller.hh"
#include "mem/protocol/DMA_Controller.hh"
#include "mem/ruby/common/MachineID.hh"
// Code for output operator
ostream&
operator<<(ostream& out, const MachineType& obj)
{
    out << MachineType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
MachineType_to_string(const MachineType& obj)
{
    switch(obj) {
      case MachineType_L1Cache:
        return "L1Cache";
      case MachineType_Directory:
        return "Directory";
      case MachineType_DMA:
        return "DMA";
      default:
        panic("Invalid range for type MachineType");
    }
}

// Code to convert from a string to the enumeration
MachineType
string_to_MachineType(const string& str)
{
    if (str == "L1Cache") {
        return MachineType_L1Cache;
    } else if (str == "Directory") {
        return MachineType_Directory;
    } else if (str == "DMA") {
        return MachineType_DMA;
    } else {
        panic("Invalid string conversion for %s, type MachineType", str);
    }
}

// Code to increment an enumeration type
MachineType&
operator++(MachineType& e)
{
    assert(e < MachineType_NUM);
    return e = MachineType(e+1);
}
/** \brief returns the base vector index for each machine type to be
  * used by NetDest
  *
  * \return the base vector index for each machine type to be used by NetDest
  * \see NetDest.hh
  */
int
MachineType_base_level(const MachineType& obj)
{
    switch(obj) {
      case MachineType_L1Cache:
        return 0;
      case MachineType_Directory:
        return 1;
      case MachineType_DMA:
        return 2;
      case MachineType_NUM:
        return 3;

      default:
        panic("Invalid range for type MachineType");
    }
}

/** \brief returns the machine type for each base vector index used by NetDest
 *
 * \return the MachineType
 */
MachineType
MachineType_from_base_level(int type)
{
    switch(type) {
      case 0:
        return MachineType_L1Cache;
      case 1:
        return MachineType_Directory;
      case 2:
        return MachineType_DMA;
      default:
        panic("Invalid range for type MachineType");
    }
}

/** \brief The return value indicates the number of components created
 * before a particular machine's components
 *
 * \return the base number of components for each machine
 */
int
MachineType_base_number(const MachineType& obj)
{
    int base = 0;
    switch(obj) {
      case MachineType_NUM:
        base += DMA_Controller::getNumControllers();
      case MachineType_DMA:
        base += Directory_Controller::getNumControllers();
      case MachineType_Directory:
        base += L1Cache_Controller::getNumControllers();
      case MachineType_L1Cache:
        break;
      default:
        panic("Invalid range for type MachineType");
    }

    return base;
}

/** \brief returns the total number of components for each machine
 * \return the total number of components for each machine
 */
int
MachineType_base_count(const MachineType& obj)
{
    switch(obj) {
case MachineType_L1Cache:
return L1Cache_Controller::getNumControllers();
case MachineType_Directory:
return Directory_Controller::getNumControllers();
case MachineType_DMA:
return DMA_Controller::getNumControllers();
      case MachineType_NUM:
      default:
        panic("Invalid range for type MachineType");
    }
}

MachineID
getL1CacheMachineID(NodeID RubyNode)
{
      MachineID mach = {MachineType_L1Cache, RubyNode};
      return mach;
}

MachineID
getDirectoryMachineID(NodeID RubyNode)
{
      MachineID mach = {MachineType_Directory, RubyNode};
      return mach;
}
MachineID
map_Address_to_DMA(const Address &addr)
{
      MachineID dma = {MachineType_DMA, 0};
      return dma;
}

MachineID
getDMAMachineID(NodeID RubyNode)
{
      MachineID mach = {MachineType_DMA, RubyNode};
      return mach;
}
