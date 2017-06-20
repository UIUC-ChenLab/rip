/** \file ResponseMsg.hh
 *
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:200
 */

#ifndef __ResponseMsg_HH__
#define __ResponseMsg_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"
#include "mem/protocol/Address.hh"
#include "mem/protocol/CoherenceResponseType.hh"
#include "mem/protocol/MachineID.hh"
#include "mem/protocol/NetDest.hh"
#include "mem/protocol/DataBlock.hh"
#include "mem/protocol/MessageSizeType.hh"
#include "mem/protocol/NetworkMessage.hh"
class ResponseMsg :  public NetworkMessage
{
  public:
    ResponseMsg
(Tick curTime) : NetworkMessage(curTime) {
        // m_Addr has no default
        m_Type = CoherenceResponseType_NUM; // default value of CoherenceResponseType
        // m_Sender has no default
        // m_Destination has no default
        // m_DataBlk has no default
        m_Dirty = false; // default value of bool
        m_MessageSize = MessageSizeType_NUM; // default value of MessageSizeType
    }
    ResponseMsg(const ResponseMsg&other)
        : NetworkMessage(other)
    {
        m_Addr = other.m_Addr;
        m_Type = other.m_Type;
        m_Sender = other.m_Sender;
        m_Destination = other.m_Destination;
        m_DataBlk = other.m_DataBlk;
        m_Dirty = other.m_Dirty;
        m_MessageSize = other.m_MessageSize;
    }
    ResponseMsg(const Tick curTime, const Address& local_Addr, const CoherenceResponseType& local_Type, const MachineID& local_Sender, const NetDest& local_Destination, const DataBlock& local_DataBlk, const bool& local_Dirty, const MessageSizeType& local_MessageSize)
        : NetworkMessage(curTime)
    {
        m_Addr = local_Addr;
        m_Type = local_Type;
        m_Sender = local_Sender;
        m_Destination = local_Destination;
        m_DataBlk = local_DataBlk;
        m_Dirty = local_Dirty;
        m_MessageSize = local_MessageSize;
    }
    MsgPtr
    clone() const
    {
         return std::shared_ptr<Message>(new ResponseMsg(*this));
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for Addr field.
     *  \return Addr field
     */
    const Address&
    getAddr() const
    {
        return m_Addr;
    }
    /** \brief Const accessor method for Type field.
     *  \return Type field
     */
    const CoherenceResponseType&
    getType() const
    {
        return m_Type;
    }
    /** \brief Const accessor method for Sender field.
     *  \return Sender field
     */
    const MachineID&
    getSender() const
    {
        return m_Sender;
    }
    /** \brief Const accessor method for Destination field.
     *  \return Destination field
     */
    const NetDest&
    getDestination() const
    {
        return m_Destination;
    }
    /** \brief Const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    const DataBlock&
    getDataBlk() const
    {
        return m_DataBlk;
    }
    /** \brief Const accessor method for Dirty field.
     *  \return Dirty field
     */
    const bool&
    getDirty() const
    {
        return m_Dirty;
    }
    /** \brief Const accessor method for MessageSize field.
     *  \return MessageSize field
     */
    const MessageSizeType&
    getMessageSize() const
    {
        return m_MessageSize;
    }
    // Non const Accessors methods for each field
    /** \brief Non-const accessor method for Addr field.
     *  \return Addr field
     */
    Address&
    getAddr()
    {
        return m_Addr;
    }
    /** \brief Non-const accessor method for Type field.
     *  \return Type field
     */
    CoherenceResponseType&
    getType()
    {
        return m_Type;
    }
    /** \brief Non-const accessor method for Sender field.
     *  \return Sender field
     */
    MachineID&
    getSender()
    {
        return m_Sender;
    }
    /** \brief Non-const accessor method for Destination field.
     *  \return Destination field
     */
    NetDest&
    getDestination()
    {
        return m_Destination;
    }
    /** \brief Non-const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    DataBlock&
    getDataBlk()
    {
        return m_DataBlk;
    }
    /** \brief Non-const accessor method for Dirty field.
     *  \return Dirty field
     */
    bool&
    getDirty()
    {
        return m_Dirty;
    }
    /** \brief Non-const accessor method for MessageSize field.
     *  \return MessageSize field
     */
    MessageSizeType&
    getMessageSize()
    {
        return m_MessageSize;
    }
    // Mutator methods for each field
    /** \brief Mutator method for Addr field */
    void
    setAddr(const Address& local_Addr)
    {
        m_Addr = local_Addr;
    }
    /** \brief Mutator method for Type field */
    void
    setType(const CoherenceResponseType& local_Type)
    {
        m_Type = local_Type;
    }
    /** \brief Mutator method for Sender field */
    void
    setSender(const MachineID& local_Sender)
    {
        m_Sender = local_Sender;
    }
    /** \brief Mutator method for Destination field */
    void
    setDestination(const NetDest& local_Destination)
    {
        m_Destination = local_Destination;
    }
    /** \brief Mutator method for DataBlk field */
    void
    setDataBlk(const DataBlock& local_DataBlk)
    {
        m_DataBlk = local_DataBlk;
    }
    /** \brief Mutator method for Dirty field */
    void
    setDirty(const bool& local_Dirty)
    {
        m_Dirty = local_Dirty;
    }
    /** \brief Mutator method for MessageSize field */
    void
    setMessageSize(const MessageSizeType& local_MessageSize)
    {
        m_MessageSize = local_MessageSize;
    }
    void print(std::ostream& out) const;
  //private:
    /** Physical address for this request */
    Address m_Addr;
    /** Type of response (Ack, Data, etc) */
    CoherenceResponseType m_Type;
    /** Node who sent the data */
    MachineID m_Sender;
    /** Node to whom the data is sent */
    NetDest m_Destination;
    /** data for the cache line */
    DataBlock m_DataBlk;
    /** Is the data dirty (different than memory)? */
    bool m_Dirty;
    /** size category of the message */
    MessageSizeType m_MessageSize;
    bool functionalWrite(Packet* param_pkt);
    bool functionalRead(Packet* param_pkt);
};
inline std::ostream&
operator<<(std::ostream& out, const ResponseMsg& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __ResponseMsg_HH__
