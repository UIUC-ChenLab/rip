/** \file Directory_TBE.hh
 *
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:200
 */

#ifndef __Directory_TBE_HH__
#define __Directory_TBE_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"
#include "mem/protocol/Address.hh"
#include "mem/protocol/Directory_State.hh"
#include "mem/protocol/DataBlock.hh"
#include "mem/protocol/MachineID.hh"
class Directory_TBE
{
  public:
    Directory_TBE
()
		{
        // m_PhysicalAddress has no default
        m_TBEState = Directory_State_I; // default value of Directory_State
        // m_DataBlk has no default
        m_Len = 0; // default value of int
        // m_DmaRequestor has no default
    }
    Directory_TBE(const Directory_TBE&other)
    {
        m_PhysicalAddress = other.m_PhysicalAddress;
        m_TBEState = other.m_TBEState;
        m_DataBlk = other.m_DataBlk;
        m_Len = other.m_Len;
        m_DmaRequestor = other.m_DmaRequestor;
    }
    Directory_TBE(const Address& local_PhysicalAddress, const Directory_State& local_TBEState, const DataBlock& local_DataBlk, const int& local_Len, const MachineID& local_DmaRequestor)
    {
        m_PhysicalAddress = local_PhysicalAddress;
        m_TBEState = local_TBEState;
        m_DataBlk = local_DataBlk;
        m_Len = local_Len;
        m_DmaRequestor = local_DmaRequestor;
    }
    Directory_TBE*
    clone() const
    {
         return new Directory_TBE(*this);
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for PhysicalAddress field.
     *  \return PhysicalAddress field
     */
    const Address&
    getPhysicalAddress() const
    {
        return m_PhysicalAddress;
    }
    /** \brief Const accessor method for TBEState field.
     *  \return TBEState field
     */
    const Directory_State&
    getTBEState() const
    {
        return m_TBEState;
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
    /** \brief Const accessor method for DmaRequestor field.
     *  \return DmaRequestor field
     */
    const MachineID&
    getDmaRequestor() const
    {
        return m_DmaRequestor;
    }
    // Non const Accessors methods for each field
    /** \brief Non-const accessor method for PhysicalAddress field.
     *  \return PhysicalAddress field
     */
    Address&
    getPhysicalAddress()
    {
        return m_PhysicalAddress;
    }
    /** \brief Non-const accessor method for TBEState field.
     *  \return TBEState field
     */
    Directory_State&
    getTBEState()
    {
        return m_TBEState;
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
    /** \brief Non-const accessor method for DmaRequestor field.
     *  \return DmaRequestor field
     */
    MachineID&
    getDmaRequestor()
    {
        return m_DmaRequestor;
    }
    // Mutator methods for each field
    /** \brief Mutator method for PhysicalAddress field */
    void
    setPhysicalAddress(const Address& local_PhysicalAddress)
    {
        m_PhysicalAddress = local_PhysicalAddress;
    }
    /** \brief Mutator method for TBEState field */
    void
    setTBEState(const Directory_State& local_TBEState)
    {
        m_TBEState = local_TBEState;
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
    /** \brief Mutator method for DmaRequestor field */
    void
    setDmaRequestor(const MachineID& local_DmaRequestor)
    {
        m_DmaRequestor = local_DmaRequestor;
    }
    void print(std::ostream& out) const;
  //private:
    /** physical address */
    Address m_PhysicalAddress;
    /** Transient State */
    Directory_State m_TBEState;
    /** Data to be written (DMA write only) */
    DataBlock m_DataBlk;
    /** ... */
    int m_Len;
    /** DMA requestor */
    MachineID m_DmaRequestor;
};
inline std::ostream&
operator<<(std::ostream& out, const Directory_TBE& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __Directory_TBE_HH__
