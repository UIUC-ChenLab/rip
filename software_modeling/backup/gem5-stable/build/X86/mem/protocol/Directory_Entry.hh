/** \file Directory_Entry.hh
 *
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:200
 */

#ifndef __Directory_Entry_HH__
#define __Directory_Entry_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"
#include "mem/protocol/Directory_State.hh"
#include "mem/protocol/NetDest.hh"
#include "mem/protocol/NetDest.hh"
#include "mem/protocol/AbstractEntry.hh"
class Directory_Entry :  public AbstractEntry
{
  public:
    Directory_Entry
()
		{
        m_DirectoryState = Directory_State_I; // default value of Directory_State
        // m_Sharers has no default
        // m_Owner has no default
    }
    Directory_Entry(const Directory_Entry&other)
        : AbstractEntry(other)
    {
        m_DirectoryState = other.m_DirectoryState;
        m_Sharers = other.m_Sharers;
        m_Owner = other.m_Owner;
    }
    Directory_Entry(const Directory_State& local_DirectoryState, const NetDest& local_Sharers, const NetDest& local_Owner)
        : AbstractEntry()
    {
        m_DirectoryState = local_DirectoryState;
        m_Sharers = local_Sharers;
        m_Owner = local_Owner;
    }
    Directory_Entry*
    clone() const
    {
         return new Directory_Entry(*this);
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for DirectoryState field.
     *  \return DirectoryState field
     */
    const Directory_State&
    getDirectoryState() const
    {
        return m_DirectoryState;
    }
    /** \brief Const accessor method for Sharers field.
     *  \return Sharers field
     */
    const NetDest&
    getSharers() const
    {
        return m_Sharers;
    }
    /** \brief Const accessor method for Owner field.
     *  \return Owner field
     */
    const NetDest&
    getOwner() const
    {
        return m_Owner;
    }
    // Non const Accessors methods for each field
    /** \brief Non-const accessor method for DirectoryState field.
     *  \return DirectoryState field
     */
    Directory_State&
    getDirectoryState()
    {
        return m_DirectoryState;
    }
    /** \brief Non-const accessor method for Sharers field.
     *  \return Sharers field
     */
    NetDest&
    getSharers()
    {
        return m_Sharers;
    }
    /** \brief Non-const accessor method for Owner field.
     *  \return Owner field
     */
    NetDest&
    getOwner()
    {
        return m_Owner;
    }
    // Mutator methods for each field
    /** \brief Mutator method for DirectoryState field */
    void
    setDirectoryState(const Directory_State& local_DirectoryState)
    {
        m_DirectoryState = local_DirectoryState;
    }
    /** \brief Mutator method for Sharers field */
    void
    setSharers(const NetDest& local_Sharers)
    {
        m_Sharers = local_Sharers;
    }
    /** \brief Mutator method for Owner field */
    void
    setOwner(const NetDest& local_Owner)
    {
        m_Owner = local_Owner;
    }
    void print(std::ostream& out) const;
  //private:
    /** Directory state */
    Directory_State m_DirectoryState;
    /** Sharers for this block */
    NetDest m_Sharers;
    /** Owner of this block */
    NetDest m_Owner;
};
inline std::ostream&
operator<<(std::ostream& out, const Directory_Entry& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __Directory_Entry_HH__
