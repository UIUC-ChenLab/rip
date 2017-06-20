/** \file DMAResponseMsg.cc
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:410
 */

#include <iostream>
#include <memory>

#include "mem/protocol/DMAResponseMsg.hh"
#include "mem/ruby/common/Global.hh"
#include "mem/ruby/system/System.hh"

using namespace std;
/** \brief Print the state of this object */
void
DMAResponseMsg::print(ostream& out) const
{
    out << "[DMAResponseMsg: ";
    out << "Type = " << m_Type << " ";
    out << "PhysicalAddress = " << m_PhysicalAddress << " ";
    out << "LineAddress = " << m_LineAddress << " ";
    out << "Destination = " << m_Destination << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "MessageSize = " << m_MessageSize << " ";
    out << "Time = " << g_system_ptr->clockPeriod() * getTime() << " ";
    out << "]";
}
bool
DMAResponseMsg::functionalWrite(Packet* param_pkt)
{
return (testAndWrite(m_LineAddress, m_DataBlk, param_pkt));

}
bool
DMAResponseMsg::functionalRead(Packet* param_pkt)
{
return (testAndRead(m_LineAddress, m_DataBlk, param_pkt));

}
