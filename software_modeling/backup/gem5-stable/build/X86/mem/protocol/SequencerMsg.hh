/** \file SequencerMsg.hh
 *
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:200
 */

#ifndef __SequencerMsg_HH__
#define __SequencerMsg_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"
#include "mem/protocol/Address.hh"
#include "mem/protocol/Address.hh"
#include "mem/protocol/SequencerRequestType.hh"
#include "mem/protocol/Address.hh"
#include "mem/protocol/RubyAccessMode.hh"
#include "mem/protocol/DataBlock.hh"
#include "mem/protocol/PrefetchBit.hh"
#include "mem/protocol/Message.hh"
class SequencerMsg :  public Message
{
  public:
    SequencerMsg
(Tick curTime) : Message(curTime) {
        // m_LineAddress has no default
        // m_PhysicalAddress has no default
        m_Type = SequencerRequestType_NULL; // default value of SequencerRequestType
        // m_ProgramCounter has no default
        m_AccessMode = RubyAccessMode_User; // default value of RubyAccessMode
        // m_DataBlk has no default
        m_Len = 0; // default value of int
        m_Prefetch = PrefetchBit_No; // default value of PrefetchBit
    }
    SequencerMsg(const SequencerMsg&other)
        : Message(other)
    {
        m_LineAddress = other.m_LineAddress;
        m_PhysicalAddress = other.m_PhysicalAddress;
        m_Type = other.m_Type;
        m_ProgramCounter = other.m_ProgramCounter;
        m_AccessMode = other.m_AccessMode;
        m_DataBlk = other.m_DataBlk;
        m_Len = other.m_Len;
        m_Prefetch = other.m_Prefetch;
    }
    SequencerMsg(const Tick curTime, const Address& local_LineAddress, const Address& local_PhysicalAddress, const SequencerRequestType& local_Type, const Address& local_ProgramCounter, const RubyAccessMode& local_AccessMode, const DataBlock& local_DataBlk, const int& local_Len, const PrefetchBit& local_Prefetch)
        : Message(curTime)
    {
        m_LineAddress = local_LineAddress;
        m_PhysicalAddress = local_PhysicalAddress;
        m_Type = local_Type;
        m_ProgramCounter = local_ProgramCounter;
        m_AccessMode = local_AccessMode;
        m_DataBlk = local_DataBlk;
        m_Len = local_Len;
        m_Prefetch = local_Prefetch;
    }
    MsgPtr
    clone() const
    {
         return std::shared_ptr<Message>(new SequencerMsg(*this));
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for LineAddress field.
     *  \return LineAddress field
     */
    const Address&
    getLineAddress() const
    {
        return m_LineAddress;
    }
    /** \brief Const accessor method for PhysicalAddress field.
     *  \return PhysicalAddress field
     */
    const Address&
    getPhysicalAddress() const
    {
        return m_PhysicalAddress;
    }
    /** \brief Const accessor method for Type field.
     *  \return Type field
     */
    const SequencerRequestType&
    getType() const
    {
        return m_Type;
    }
    /** \brief Const accessor method for ProgramCounter field.
     *  \return ProgramCounter field
     */
    const Address&
    getProgramCounter() const
    {
        return m_ProgramCounter;
    }
    /** \brief Const accessor method for AccessMode field.
     *  \return AccessMode field
     */
    const RubyAccessMode&
    getAccessMode() const
    {
        return m_AccessMode;
    }
    /** \brief Const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    const DataBlock&
    getDataBlk() const
    {
        return m_DataBlk;
    }
    /** \brief Const accessor method for Len field.
     *  \return Len field
     */
    const int&
    getLen() const
    {
        return m_Len;
    }
    /** \brief Const accessor method for Prefetch field.
     *  \return Prefetch field
     */
    const PrefetchBit&
    getPrefetch() const
    {
        return m_Prefetch;
    }
    // Non const Accessors methods for each field
    /** \brief Non-const accessor method for LineAddress field.
     *  \return LineAddress field
     */
    Address&
    getLineAddress()
    {
        return m_LineAddress;
    }
    /** \brief Non-const accessor method for PhysicalAddress field.
     *  \return PhysicalAddress field
     */
    Address&
    getPhysicalAddress()
    {
        return m_PhysicalAddress;
    }
    /** \brief Non-const accessor method for Type field.
     *  \return Type field
     */
    SequencerRequestType&
    getType()
    {
        return m_Type;
    }
    /** \brief Non-const accessor method for ProgramCounter field.
     *  \return ProgramCounter field
     */
    Address&
    getProgramCounter()
    {
        return m_ProgramCounter;
    }
    /** \brief Non-const accessor method for AccessMode field.
     *  \return AccessMode field
     */
    RubyAccessMode&
    getAccessMode()
    {
        return m_AccessMode;
    }
    /** \brief Non-const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    DataBlock&
    getDataBlk()
    {
        return m_DataBlk;
    }
    /** \brief Non-const accessor method for Len field.
     *  \return Len field
     */
    int&
    getLen()
    {
        return m_Len;
    }
    /** \brief Non-const accessor method for Prefetch field.
     *  \return Prefetch field
     */
    PrefetchBit&
    getPrefetch()
    {
        return m_Prefetch;
    }
    // Mutator methods for each field
    /** \brief Mutator method for LineAddress field */
    void
    setLineAddress(const Address& local_LineAddress)
    {
        m_LineAddress = local_LineAddress;
    }
    /** \brief Mutator method for PhysicalAddress field */
    void
    setPhysicalAddress(const Address& local_PhysicalAddress)
    {
        m_PhysicalAddress = local_PhysicalAddress;
    }
    /** \brief Mutator method for Type field */
    void
    setType(const SequencerRequestType& local_Type)
    {
        m_Type = local_Type;
    }
    /** \brief Mutator method for ProgramCounter field */
    void
    setProgramCounter(const Address& local_ProgramCounter)
    {
        m_ProgramCounter = local_ProgramCounter;
    }
    /** \brief Mutator method for AccessMode field */
    void
    setAccessMode(const RubyAccessMode& local_AccessMode)
    {
        m_AccessMode = local_AccessMode;
    }
    /** \brief Mutator method for DataBlk field */
    void
    setDataBlk(const DataBlock& local_DataBlk)
    {
        m_DataBlk = local_DataBlk;
    }
    /** \brief Mutator method for Len field */
    void
    setLen(const int& local_Len)
    {
        m_Len = local_Len;
    }
    /** \brief Mutator method for Prefetch field */
    void
    setPrefetch(const PrefetchBit& local_Prefetch)
    {
        m_Prefetch = local_Prefetch;
    }
    void print(std::ostream& out) const;
  //private:
    /** Line address for this request */
    Address m_LineAddress;
    /** Physical address for this request */
    Address m_PhysicalAddress;
    /** Type of request (LD, ST, etc) */
    SequencerRequestType m_Type;
    /** Program counter of the instruction that caused the miss */
    Address m_ProgramCounter;
    /** user/supervisor access type */
    RubyAccessMode m_AccessMode;
    /** Data */
    DataBlock m_DataBlk;
    /** size in bytes of access */
    int m_Len;
    /** Is this a prefetch request */
    PrefetchBit m_Prefetch;
    bool functionalWrite(Packet* param_pkt);
    bool functionalRead(Packet* param_pkt);
};
inline std::ostream&
operator<<(std::ostream& out, const SequencerMsg& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __SequencerMsg_HH__
