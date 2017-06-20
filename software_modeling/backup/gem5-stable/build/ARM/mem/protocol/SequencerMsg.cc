/** \file SequencerMsg.cc
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:410
 */

#include <iostream>
#include <memory>

#include "mem/protocol/SequencerMsg.hh"
#include "mem/ruby/common/Global.hh"
#include "mem/ruby/system/System.hh"

using namespace std;
/** \brief Print the state of this object */
void
SequencerMsg::print(ostream& out) const
{
    out << "[SequencerMsg: ";
    out << "LineAddress = " << m_LineAddress << " ";
    out << "PhysicalAddress = " << m_PhysicalAddress << " ";
    out << "Type = " << m_Type << " ";
    out << "ProgramCounter = " << m_ProgramCounter << " ";
    out << "AccessMode = " << m_AccessMode << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "Len = " << m_Len << " ";
    out << "Prefetch = " << m_Prefetch << " ";
    out << "Time = " << g_system_ptr->clockPeriod() * getTime() << " ";
    out << "]";
}
bool
SequencerMsg::functionalWrite(Packet* param_pkt)
{
return (testAndWrite(m_PhysicalAddress, m_DataBlk, param_pkt));

}
bool
SequencerMsg::functionalRead(Packet* param_pkt)
{
return (testAndRead(m_PhysicalAddress, m_DataBlk, param_pkt));

}
