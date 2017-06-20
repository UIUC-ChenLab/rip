/** \file L1Cache_Entry.hh
 *
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:200
 */

#ifndef __L1Cache_Entry_HH__
#define __L1Cache_Entry_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"
#include "mem/protocol/L1Cache_State.hh"
#include "mem/protocol/DataBlock.hh"
#include "mem/protocol/AbstractCacheEntry.hh"
class L1Cache_Entry :  public AbstractCacheEntry
{
  public:
    L1Cache_Entry
()
		{
        m_CacheState = L1Cache_State_NUM; // default value of L1Cache_State
        m_Dirty = false; // default value of bool
        // m_DataBlk has no default
    }
    L1Cache_Entry(const L1Cache_Entry&other)
        : AbstractCacheEntry(other)
    {
        m_CacheState = other.m_CacheState;
        m_Dirty = other.m_Dirty;
        m_DataBlk = other.m_DataBlk;
    }
    L1Cache_Entry(const L1Cache_State& local_CacheState, const bool& local_Dirty, const DataBlock& local_DataBlk)
        : AbstractCacheEntry()
    {
        m_CacheState = local_CacheState;
        m_Dirty = local_Dirty;
        m_DataBlk = local_DataBlk;
    }
    L1Cache_Entry*
    clone() const
    {
         return new L1Cache_Entry(*this);
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for CacheState field.
     *  \return CacheState field
     */
    const L1Cache_State&
    getCacheState() const
    {
        return m_CacheState;
    }
    /** \brief Const accessor method for Dirty field.
     *  \return Dirty field
     */
    const bool&
    getDirty() const
    {
        return m_Dirty;
    }
    /** \brief Const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    const DataBlock&
    getDataBlk() const
    {
        return m_DataBlk;
    }
    // Non const Accessors methods for each field
    /** \brief Non-const accessor method for CacheState field.
     *  \return CacheState field
     */
    L1Cache_State&
    getCacheState()
    {
        return m_CacheState;
    }
    /** \brief Non-const accessor method for Dirty field.
     *  \return Dirty field
     */
    bool&
    getDirty()
    {
        return m_Dirty;
    }
    /** \brief Non-const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    DataBlock&
    getDataBlk()
    {
        return m_DataBlk;
    }
    // Mutator methods for each field
    /** \brief Mutator method for CacheState field */
    void
    setCacheState(const L1Cache_State& local_CacheState)
    {
        m_CacheState = local_CacheState;
    }
    /** \brief Mutator method for Dirty field */
    void
    setDirty(const bool& local_Dirty)
    {
        m_Dirty = local_Dirty;
    }
    /** \brief Mutator method for DataBlk field */
    void
    setDataBlk(const DataBlock& local_DataBlk)
    {
        m_DataBlk = local_DataBlk;
    }
    void print(std::ostream& out) const;
  //private:
    /** cache state */
    L1Cache_State m_CacheState;
    /** Is the data dirty (different than memory)? */
    bool m_Dirty;
    /** Data in the block */
    DataBlock m_DataBlk;
};
inline std::ostream&
operator<<(std::ostream& out, const L1Cache_Entry& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __L1Cache_Entry_HH__
