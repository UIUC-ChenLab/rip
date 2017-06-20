/*
 * Copyright (c) 2012-2015 ARM Limited
 * All rights reserved
 *
 * The license below extends only to copyright in the software and shall
 * not be construed as granting a license to any other intellectual
 * property including but not limited to intellectual property relating
 * to a hardware implementation of the functionality of the software
 * licensed hereunder.  You may use the software subject to the license
 * terms below provided that you ensure that this notice is replicated
 * unmodified and in its entirety in all distributions of the software,
 * modified or unmodified, in source code or in binary form.
 *
 * Copyright (c) 2006 The Regents of The University of Michigan
 * Copyright (c) 2010 Advanced Micro Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Ron Dreslinski
 *          Steve Reinhardt
 *          Ali Saidi
 *          Andreas Hansson
 */

/**
 * @file
 * Declaration of the Packet class.
 */

#ifndef __MEM_PACKET_HH__
#define __MEM_PACKET_HH__

#include <bitset>
#include <cassert>
#include <list>

#include "base/cast.hh"
#include "base/compiler.hh"
#include "base/flags.hh"
#include "base/misc.hh"
#include "base/printable.hh"
#include "base/types.hh"
#include "mem/request.hh"
#include "sim/core.hh"

class Packet;
typedef Packet *PacketPtr;
typedef uint8_t* PacketDataPtr;
typedef std::list<PacketPtr> PacketList;

class MemCmd
{
    friend class Packet;

  public:
    /**
     * List of all commands associated with a packet.
     */
    enum Command
    {
        InvalidCmd,
        ReadReq,
        ReadResp,
        ReadRespWithInvalidate,
        WriteReq,
        WriteResp,
        Writeback,
        SoftPFReq,
        HardPFReq,
        SoftPFResp,
        HardPFResp,
        WriteInvalidateReq,
        WriteInvalidateResp,
        UpgradeReq,
        SCUpgradeReq,           // Special "weak" upgrade for StoreCond
        UpgradeResp,
        SCUpgradeFailReq,       // Failed SCUpgradeReq in MSHR (never sent)
        UpgradeFailResp,        // Valid for SCUpgradeReq only
        ReadExReq,
        ReadExResp,
        LoadLockedReq,
        StoreCondReq,
        StoreCondFailReq,       // Failed StoreCondReq in MSHR (never sent)
        StoreCondResp,
        SwapReq,
        SwapResp,
        MessageReq,
        MessageResp,
        // Error responses
        // @TODO these should be classified as responses rather than
        // requests; coding them as requests initially for backwards
        // compatibility
        InvalidDestError,  // packet dest field invalid
        BadAddressError,   // memory address invalid
        FunctionalReadError, // unable to fulfill functional read
        FunctionalWriteError, // unable to fulfill functional write
        // Fake simulator-only commands
        PrintReq,       // Print state matching address
        FlushReq,      //request for a cache flush
        InvalidationReq,   // request for address to be invalidated from lsq
        NUM_MEM_CMDS
    };

  private:
    /**
     * List of command attributes.
     */
    enum Attribute
    {
        IsRead,         //!< Data flows from responder to requester
        IsWrite,        //!< Data flows from requester to responder
        IsUpgrade,
        IsInvalidate,
        NeedsExclusive, //!< Requires exclusive copy to complete in-cache
        IsRequest,      //!< Issued by requester
        IsResponse,     //!< Issue by responder
        NeedsResponse,  //!< Requester needs response from target
        IsSWPrefetch,
        IsHWPrefetch,
        IsLlsc,         //!< Alpha/MIPS LL or SC access
        HasData,        //!< There is an associated payload
        IsError,        //!< Error response
        IsPrint,        //!< Print state matching address (for debugging)
        IsFlush,        //!< Flush the address from caches
        NUM_COMMAND_ATTRIBUTES
    };

    /**
     * Structure that defines attributes and other data associated
     * with a Command.
     */
    struct CommandInfo
    {
        /// Set of attribute flags.
        const std::bitset<NUM_COMMAND_ATTRIBUTES> attributes;
        /// Corresponding response for requests; InvalidCmd if no
        /// response is applicable.
        const Command response;
        /// String representation (for printing)
        const std::string str;
    };

    /// Array to map Command enum to associated info.
    static const CommandInfo commandInfo[];

  private:

    Command cmd;

    bool
    testCmdAttrib(MemCmd::Attribute attrib) const
    {
        return commandInfo[cmd].attributes[attrib] != 0;
    }

  public:

    bool isRead() const            { return testCmdAttrib(IsRead); }
    bool isWrite() const           { return testCmdAttrib(IsWrite); }
    bool isUpgrade() const         { return testCmdAttrib(IsUpgrade); }
    bool isRequest() const         { return testCmdAttrib(IsRequest); }
    bool isResponse() const        { return testCmdAttrib(IsResponse); }
    bool needsExclusive() const    { return testCmdAttrib(NeedsExclusive); }
    bool needsResponse() const     { return testCmdAttrib(NeedsResponse); }
    bool isInvalidate() const      { return testCmdAttrib(IsInvalidate); }
    bool isWriteInvalidate() const { return testCmdAttrib(IsWrite) &&
                                            testCmdAttrib(IsInvalidate); }

    /**
     * Check if this particular packet type carries payload data. Note
     * that this does not reflect if the data pointer of the packet is
     * valid or not.
     */
    bool hasData() const        { return testCmdAttrib(HasData); }
    bool isLLSC() const         { return testCmdAttrib(IsLlsc); }
    bool isSWPrefetch() const   { return testCmdAttrib(IsSWPrefetch); }
    bool isHWPrefetch() const   { return testCmdAttrib(IsHWPrefetch); }
    bool isPrefetch() const     { return testCmdAttrib(IsSWPrefetch) ||
                                         testCmdAttrib(IsHWPrefetch); }
    bool isError() const        { return testCmdAttrib(IsError); }
    bool isPrint() const        { return testCmdAttrib(IsPrint); }
    bool isFlush() const        { return testCmdAttrib(IsFlush); }

    const Command
    responseCommand() const
    {
        return commandInfo[cmd].response;
    }

    /// Return the string to a cmd given by idx.
    const std::string &toString() const { return commandInfo[cmd].str; }
    int toInt() const { return (int)cmd; }

    MemCmd(Command _cmd) : cmd(_cmd) { }
    MemCmd(int _cmd) : cmd((Command)_cmd) { }
    MemCmd() : cmd(InvalidCmd) { }

    bool operator==(MemCmd c2) const { return (cmd == c2.cmd); }
    bool operator!=(MemCmd c2) const { return (cmd != c2.cmd); }
};

/**
 * A Packet is used to encapsulate a transfer between two objects in
 * the memory system (e.g., the L1 and L2 cache).  (In contrast, a
 * single Request travels all the way from the requester to the
 * ultimate destination and back, possibly being conveyed by several
 * different Packets along the way.)
 */
class Packet : public Printable
{
  public:
    typedef uint32_t FlagsType;
    typedef ::Flags<FlagsType> Flags;

  private:
    static const FlagsType PUBLIC_FLAGS           = 0x00000000;
    static const FlagsType PRIVATE_FLAGS          = 0x00007F0F;
    static const FlagsType COPY_FLAGS             = 0x0000000F;

    static const FlagsType SHARED                 = 0x00000001;
    // Special control flags
    /// Special timing-mode atomic snoop for multi-level coherence.
    static const FlagsType EXPRESS_SNOOP          = 0x00000002;
    /// Does supplier have exclusive copy?
    /// Useful for multi-level coherence.
    static const FlagsType SUPPLY_EXCLUSIVE       = 0x00000004;
    // Snoop response flags
    static const FlagsType MEM_INHIBIT            = 0x00000008;
    /// Are the 'addr' and 'size' fields valid?
    static const FlagsType VALID_ADDR             = 0x00000100;
    static const FlagsType VALID_SIZE             = 0x00000200;
    /// Is the data pointer set to a value that shouldn't be freed
    /// when the packet is destroyed?
    static const FlagsType STATIC_DATA            = 0x00001000;
    /// The data pointer points to a value that should be freed when
    /// the packet is destroyed. The pointer is assumed to be pointing
    /// to an array, and delete [] is consequently called
    static const FlagsType DYNAMIC_DATA           = 0x00002000;
    /// suppress the error if this packet encounters a functional
    /// access failure.
    static const FlagsType SUPPRESS_FUNC_ERROR    = 0x00008000;
    // Signal block present to squash prefetch and cache evict packets
    // through express snoop flag
    static const FlagsType BLOCK_CACHED          = 0x00010000;

    Flags flags;

  public:
    typedef MemCmd::Command Command;

    /// The command field of the packet.
    MemCmd cmd;

    /// A pointer to the original request.
    const RequestPtr req;

  private:
   /**
    * A pointer to the data being transfered.  It can be differnt
    * sizes at each level of the heirarchy so it belongs in the
    * packet, not request. This may or may not be populated when a
    * responder recieves the packet. If not populated it memory should
    * be allocated.
    */
    PacketDataPtr data;

    /// The address of the request.  This address could be virtual or
    /// physical, depending on the system configuration.
    Addr addr;

    /// True if the request targets the secure memory space.
    bool _isSecure;

    /// The size of the request or transfer.
    unsigned size;

    /**
     * The original value of the command field.  Only valid when the
     * current command field is an error condition; in that case, the
     * previous contents of the command field are copied here.  This
     * field is *not* set on non-error responses.
     */
    MemCmd origCmd;

    /**
     * Track the bytes found that satisfy a functional read.
     */
    std::vector<bool> bytesValid;

  public:

    /**
     * The extra delay from seeing the packet until the header is
     * transmitted. This delay is used to communicate the crossbar
     * forwarding latency to the neighbouring object (e.g. a cache)
     * that actually makes the packet wait. As the delay is relative,
     * a 32-bit unsigned should be sufficient.
     */
    uint32_t headerDelay;

    /**
     * The extra pipelining delay from seeing the packet until the end of
     * payload is transmitted by the component that provided it (if
     * any). This includes the header delay. Similar to the header
     * delay, this is used to make up for the fact that the
     * crossbar does not make the packet wait. As the delay is
     * relative, a 32-bit unsigned should be sufficient.
     */
    uint32_t payloadDelay;

    /**
     * A virtual base opaque structure used to hold state associated
     * with the packet (e.g., an MSHR), specific to a MemObject that
     * sees the packet. A pointer to this state is returned in the
     * packet's response so that the MemObject in question can quickly
     * look up the state needed to process it. A specific subclass
     * would be derived from this to carry state specific to a
     * particular sending device.
     *
     * As multiple MemObjects may add their SenderState throughout the
     * memory system, the SenderStates create a stack, where a
     * MemObject can add a new Senderstate, as long as the
     * predecessing SenderState is restored when the response comes
     * back. For this reason, the predecessor should always be
     * populated with the current SenderState of a packet before
     * modifying the senderState field in the request packet.
     */
    struct SenderState
    {
        SenderState* predecessor;
        SenderState() : predecessor(NULL) {}
        virtual ~SenderState() {}
    };

    /**
     * Object used to maintain state of a PrintReq.  The senderState
     * field of a PrintReq should always be of this type.
     */
    class PrintReqState : public SenderState
    {
      private:
        /**
         * An entry in the label stack.
         */
        struct LabelStackEntry
        {
            const std::string label;
            std::string *prefix;
            bool labelPrinted;
            LabelStackEntry(const std::string &_label, std::string *_prefix);
        };

        typedef std::list<LabelStackEntry> LabelStack;
        LabelStack labelStack;

        std::string *curPrefixPtr;

      public:
        std::ostream &os;
        const int verbosity;

        PrintReqState(std::ostream &os, int verbosity = 0);
        ~PrintReqState();

        /**
         * Returns the current line prefix.
         */
        const std::string &curPrefix() { return *curPrefixPtr; }

        /**
         * Push a label onto the label stack, and prepend the given
         * prefix string onto the current prefix.  Labels will only be
         * printed if an object within the label's scope is printed.
         */
        void pushLabel(const std::string &lbl,
                       const std::string &prefix = "  ");

        /**
         * Pop a label off the label stack.
         */
        void popLabel();

        /**
         * Print all of the pending unprinted labels on the
         * stack. Called by printObj(), so normally not called by
         * users unless bypassing printObj().
         */
        void printLabels();

        /**
         * Print a Printable object to os, because it matched the
         * address on a PrintReq.
         */
        void printObj(Printable *obj);
    };

    /**
     * This packet's sender state.  Devices should use dynamic_cast<>
     * to cast to the state appropriate to the sender.  The intent of
     * this variable is to allow a device to attach extra information
     * to a request. A response packet must return the sender state
     * that was attached to the original request (even if a new packet
     * is created).
     */
    SenderState *senderState;

    /**
     * Push a new sender state to the packet and make the current
     * sender state the predecessor of the new one. This should be
     * prefered over direct manipulation of the senderState member
     * variable.
     *
     * @param sender_state SenderState to push at the top of the stack
     */
    void pushSenderState(SenderState *sender_state);

    /**
     * Pop the top of the state stack and return a pointer to it. This
     * assumes the current sender state is not NULL. This should be
     * preferred over direct manipulation of the senderState member
     * variable.
     *
     * @return The current top of the stack
     */
    SenderState *popSenderState();

    /**
     * Go through the sender state stack and return the first instance
     * that is of type T (as determined by a dynamic_cast). If there
     * is no sender state of type T, NULL is returned.
     *
     * @return The topmost state of type T
     */
    template <typename T>
    T * findNextSenderState() const
    {
        T *t = NULL;
        SenderState* sender_state = senderState;
        while (t == NULL && sender_state != NULL) {
            t = dynamic_cast<T*>(sender_state);
            sender_state = sender_state->predecessor;
        }
        return t;
    }

    /// Return the string name of the cmd field (for debugging and
    /// tracing).
    const std::string &cmdString() const { return cmd.toString(); }

    /// Return the index of this command.
    inline int cmdToIndex() const { return cmd.toInt(); }

    bool isRead() const              { return cmd.isRead(); }
    bool isWrite() const             { return cmd.isWrite(); }
    bool isUpgrade()  const          { return cmd.isUpgrade(); }
    bool isRequest() const           { return cmd.isRequest(); }
    bool isResponse() const          { return cmd.isResponse(); }
    bool needsExclusive() const      { return cmd.needsExclusive(); }
    bool needsResponse() const       { return cmd.needsResponse(); }
    bool isInvalidate() const        { return cmd.isInvalidate(); }
    bool isWriteInvalidate() const   { return cmd.isWriteInvalidate(); }
    bool hasData() const             { return cmd.hasData(); }
    bool isLLSC() const              { return cmd.isLLSC(); }
    bool isError() const             { return cmd.isError(); }
    bool isPrint() const             { return cmd.isPrint(); }
    bool isFlush() const             { return cmd.isFlush(); }

    // Snoop flags
    void assertMemInhibit()
    {
        assert(isRequest());
        assert(!flags.isSet(MEM_INHIBIT));
        flags.set(MEM_INHIBIT);
    }
    bool memInhibitAsserted() const { return flags.isSet(MEM_INHIBIT); }
    void assertShared()             { flags.set(SHARED); }
    bool sharedAsserted() const     { return flags.isSet(SHARED); }

    // Special control flags
    void setExpressSnoop()          { flags.set(EXPRESS_SNOOP); }
    bool isExpressSnoop() const     { return flags.isSet(EXPRESS_SNOOP); }
    void setSupplyExclusive()       { flags.set(SUPPLY_EXCLUSIVE); }
    void clearSupplyExclusive()     { flags.clear(SUPPLY_EXCLUSIVE); }
    bool isSupplyExclusive() const  { return flags.isSet(SUPPLY_EXCLUSIVE); }
    void setSuppressFuncError()     { flags.set(SUPPRESS_FUNC_ERROR); }
    bool suppressFuncError() const  { return flags.isSet(SUPPRESS_FUNC_ERROR); }
    void setBlockCached()          { flags.set(BLOCK_CACHED); }
    bool isBlockCached() const     { return flags.isSet(BLOCK_CACHED); }

    // Network error conditions... encapsulate them as methods since
    // their encoding keeps changing (from result field to command
    // field, etc.)
    void
    setBadAddress()
    {
        assert(isResponse());
        cmd = MemCmd::BadAddressError;
    }

    bool hadBadAddress() const { return cmd == MemCmd::BadAddressError; }
    void copyError(Packet *pkt) { assert(pkt->isError()); cmd = pkt->cmd; }

    Addr getAddr() const { assert(flags.isSet(VALID_ADDR)); return addr; }
    /**
     * Update the address of this packet mid-transaction. This is used
     * by the address mapper to change an already set address to a new
     * one based on the system configuration. It is intended to remap
     * an existing address, so it asserts that the current address is
     * valid.
     */
    void setAddr(Addr _addr) { assert(flags.isSet(VALID_ADDR)); addr = _addr; }

    unsigned getSize() const  { assert(flags.isSet(VALID_SIZE)); return size; }
    Addr getOffset(int blkSize) const { return getAddr() & (Addr)(blkSize - 1); }

    bool isSecure() const
    {
        assert(flags.isSet(VALID_ADDR));
        return _isSecure;
    }

    /**
     * It has been determined that the SC packet should successfully update
     * memory.  Therefore, convert this SC packet to a normal write.
     */
    void
    convertScToWrite()
    {
        assert(isLLSC());
        assert(isWrite());
        cmd = MemCmd::WriteReq;
    }

    /**
     * When ruby is in use, Ruby will monitor the cache line and thus M5 
     * phys memory should treat LL ops as normal reads. 
     */
    void
    convertLlToRead()
    {
        assert(isLLSC());
        assert(isRead());
        cmd = MemCmd::ReadReq;
    }

    /**
     * Constructor.  Note that a Request object must be constructed
     * first, but the Requests's physical address and size fields need
     * not be valid. The command must be supplied.
     */
    Packet(const RequestPtr _req, MemCmd _cmd)
        :  cmd(_cmd), req(_req), data(nullptr), addr(0), _isSecure(false),
           size(0), headerDelay(0), payloadDelay(0),
           senderState(NULL)
    {
        if (req->hasPaddr()) {
            addr = req->getPaddr();
            flags.set(VALID_ADDR);
            _isSecure = req->isSecure();
        }
        if (req->hasSize()) {
            size = req->getSize();
            flags.set(VALID_SIZE);
        }
    }

    /**
     * Alternate constructor if you are trying to create a packet with
     * a request that is for a whole block, not the address from the
     * req.  this allows for overriding the size/addr of the req.
     */
    Packet(const RequestPtr _req, MemCmd _cmd, int _blkSize)
        :  cmd(_cmd), req(_req), data(nullptr), addr(0), _isSecure(false),
           headerDelay(0), payloadDelay(0),
           senderState(NULL)
    {
        if (req->hasPaddr()) {
            addr = req->getPaddr() & ~(_blkSize - 1);
            flags.set(VALID_ADDR);
            _isSecure = req->isSecure();
        }
        size = _blkSize;
        flags.set(VALID_SIZE);
    }

    /**
     * Alternate constructor for copying a packet.  Copy all fields
     * *except* if the original packet's data was dynamic, don't copy
     * that, as we can't guarantee that the new packet's lifetime is
     * less than that of the original packet.  In this case the new
     * packet should allocate its own data.
     */
    Packet(PacketPtr pkt, bool clear_flags, bool alloc_data)
        :  cmd(pkt->cmd), req(pkt->req),
           data(nullptr),
           addr(pkt->addr), _isSecure(pkt->_isSecure), size(pkt->size),
           bytesValid(pkt->bytesValid),
           headerDelay(pkt->headerDelay),
           payloadDelay(pkt->payloadDelay),
           senderState(pkt->senderState)
    {
        if (!clear_flags)
            flags.set(pkt->flags & COPY_FLAGS);

        flags.set(pkt->flags & (VALID_ADDR|VALID_SIZE));

        // should we allocate space for data, or not, the express
        // snoops do not need to carry any data as they only serve to
        // co-ordinate state changes
        if (alloc_data) {
            // even if asked to allocate data, if the original packet
            // holds static data, then the sender will not be doing
            // any memcpy on receiving the response, thus we simply
            // carry the pointer forward
            if (pkt->flags.isSet(STATIC_DATA)) {
                data = pkt->data;
                flags.set(STATIC_DATA);
            } else {
                allocate();
            }
        }
    }

    /**
     * Generate the appropriate read MemCmd based on the Request flags.
     */
    static MemCmd
    makeReadCmd(const RequestPtr req)
    {
        if (req->isLLSC())
            return MemCmd::LoadLockedReq;
        else if (req->isPrefetch())
            return MemCmd::SoftPFReq;
        else
            return MemCmd::ReadReq;
    }

    /**
     * Generate the appropriate write MemCmd based on the Request flags.
     */
    static MemCmd
    makeWriteCmd(const RequestPtr req)
    {
        if (req->isLLSC())
            return MemCmd::StoreCondReq;
        else if (req->isSwap())
            return MemCmd::SwapReq;
        else
            return MemCmd::WriteReq;
    }

    /**
     * Constructor-like methods that return Packets based on Request objects.
     * Fine-tune the MemCmd type if it's not a vanilla read or write.
     */
    static PacketPtr
    createRead(const RequestPtr req)
    {
        return new Packet(req, makeReadCmd(req));
    }

    static PacketPtr
    createWrite(const RequestPtr req)
    {
        return new Packet(req, makeWriteCmd(req));
    }

    /**
     * clean up packet variables
     */
    ~Packet()
    {
        // Delete the request object if this is a request packet which
        // does not need a response, because the requester will not get
        // a chance. If the request packet needs a response then the
        // request will be deleted on receipt of the response
        // packet. We also make sure to never delete the request for
        // express snoops, even for cases when responses are not
        // needed (CleanEvict and Writeback), since the snoop packet
        // re-uses the same request.
        if (req && isRequest() && !needsResponse() &&
            !isExpressSnoop()) {
            delete req;
        }
        deleteData();
    }

    /**
     * Take a request packet and modify it in place to be suitable for
     * returning as a response to that request.
     */
    void
    makeResponse()
    {
        assert(needsResponse());
        assert(isRequest());
        origCmd = cmd;
        cmd = cmd.responseCommand();

        // responses are never express, even if the snoop that
        // triggered them was
        flags.clear(EXPRESS_SNOOP);
    }

    void
    makeAtomicResponse()
    {
        makeResponse();
    }

    void
    makeTimingResponse()
    {
        makeResponse();
    }

    void
    setFunctionalResponseStatus(bool success)
    {
        if (!success) {
            if (isWrite()) {
                cmd = MemCmd::FunctionalWriteError;
            } else {
                cmd = MemCmd::FunctionalReadError;
            }
        }
    }

    void
    setSize(unsigned size)
    {
        assert(!flags.isSet(VALID_SIZE));

        this->size = size;
        flags.set(VALID_SIZE);
    }


    /**
     * Set the data pointer to the following value that should not be
     * freed. Static data allows us to do a single memcpy even if
     * multiple packets are required to get from source to destination
     * and back. In essence the pointer is set calling dataStatic on
     * the original packet, and whenever this packet is copied and
     * forwarded the same pointer is passed on. When a packet
     * eventually reaches the destination holding the data, it is
     * copied once into the location originally set. On the way back
     * to the source, no copies are necessary.
     */
    template <typename T>
    void
    dataStatic(T *p)
    {
        assert(flags.noneSet(STATIC_DATA|DYNAMIC_DATA));
        data = (PacketDataPtr)p;
        flags.set(STATIC_DATA);
    }

    /**
     * Set the data pointer to the following value that should not be
     * freed. This version of the function allows the pointer passed
     * to us to be const. To avoid issues down the line we cast the
     * constness away, the alternative would be to keep both a const
     * and non-const data pointer and cleverly choose between
     * them. Note that this is only allowed for static data.
     */
    template <typename T>
    void
    dataStaticConst(const T *p)
    {
        assert(flags.noneSet(STATIC_DATA|DYNAMIC_DATA));
        data = const_cast<PacketDataPtr>(p);
        flags.set(STATIC_DATA);
    }

    /**
     * Set the data pointer to a value that should have delete []
     * called on it. Dynamic data is local to this packet, and as the
     * packet travels from source to destination, forwarded packets
     * will allocate their own data. When a packet reaches the final
     * destination it will populate the dynamic data of that specific
     * packet, and on the way back towards the source, memcpy will be
     * invoked in every step where a new packet was created e.g. in
     * the caches. Ultimately when the response reaches the source a
     * final memcpy is needed to extract the data from the packet
     * before it is deallocated.
     */
    template <typename T>
    void
    dataDynamic(T *p)
    {
        assert(flags.noneSet(STATIC_DATA|DYNAMIC_DATA));
        data = (PacketDataPtr)p;
        flags.set(DYNAMIC_DATA);
    }

    /**
     * get a pointer to the data ptr.
     */
    template <typename T>
    T*
    getPtr()
    {
        assert(flags.isSet(STATIC_DATA|DYNAMIC_DATA));
        return (T*)data;
    }

    template <typename T>
    const T*
    getConstPtr() const
    {
        assert(flags.isSet(STATIC_DATA|DYNAMIC_DATA));
        return (const T*)data;
    }

    /**
     * return the value of what is pointed to in the packet.
     */
    template <typename T>
    T get() const;

    /**
     * set the value in the data pointer to v.
     */
    template <typename T>
    void set(T v);

    /**
     * Copy data into the packet from the provided pointer.
     */
    void
    setData(const uint8_t *p)
    {
        // we should never be copying data onto itself, which means we
        // must idenfity packets with static data, as they carry the
        // same pointer from source to destination and back
        assert(p != getPtr<uint8_t>() || flags.isSet(STATIC_DATA));

        if (p != getPtr<uint8_t>())
            // for packet with allocated dynamic data, we copy data from
            // one to the other, e.g. a forwarded response to a response
            std::memcpy(getPtr<uint8_t>(), p, getSize());
    }

    /**
     * Copy data into the packet from the provided block pointer,
     * which is aligned to the given block size.
     */
    void
    setDataFromBlock(const uint8_t *blk_data, int blkSize)
    {
        setData(blk_data + getOffset(blkSize));
    }

    /**
     * Copy data from the packet to the provided block pointer, which
     * is aligned to the given block size.
     */
    void
    writeData(uint8_t *p) const
    {
        std::memcpy(p, getConstPtr<uint8_t>(), getSize());
    }

    /**
     * Copy data from the packet to the memory at the provided pointer.
     */
    void
    writeDataToBlock(uint8_t *blk_data, int blkSize) const
    {
        writeData(blk_data + getOffset(blkSize));
    }

    /**
     * delete the data pointed to in the data pointer. Ok to call to
     * matter how data was allocted.
     */
    void
    deleteData()
    {
        if (flags.isSet(DYNAMIC_DATA))
            delete [] data;

        flags.clear(STATIC_DATA|DYNAMIC_DATA);
        data = NULL;
    }

    /** Allocate memory for the packet. */
    void
    allocate()
    {
        assert(flags.noneSet(STATIC_DATA|DYNAMIC_DATA));
        flags.set(DYNAMIC_DATA);
        data = new uint8_t[getSize()];
    }

    /**
     * Check a functional request against a memory value stored in
     * another packet (i.e. an in-transit request or
     * response). Returns true if the current packet is a read, and
     * the other packet provides the data, which is then copied to the
     * current packet. If the current packet is a write, and the other
     * packet intersects this one, then we update the data
     * accordingly.
     */
    bool
    checkFunctional(PacketPtr other)
    {
        // all packets that are carrying a payload should have a valid
        // data pointer
        return checkFunctional(other, other->getAddr(), other->isSecure(),
                               other->getSize(),
                               other->hasData() ?
                               other->getPtr<uint8_t>() : NULL);
    }

    /**
     * Check a functional request against a memory value represented
     * by a base/size pair and an associated data array. If the
     * current packet is a read, it may be satisfied by the memory
     * value. If the current packet is a write, it may update the
     * memory value.
     */
    bool
    checkFunctional(Printable *obj, Addr base, bool is_secure, int size,
                    uint8_t *_data);

    /**
     * Push label for PrintReq (safe to call unconditionally).
     */
    void
    pushLabel(const std::string &lbl)
    {
        if (isPrint())
            safe_cast<PrintReqState*>(senderState)->pushLabel(lbl);
    }

    /**
     * Pop label for PrintReq (safe to call unconditionally).
     */
    void
    popLabel()
    {
        if (isPrint())
            safe_cast<PrintReqState*>(senderState)->popLabel();
    }

    void print(std::ostream &o, int verbosity = 0,
               const std::string &prefix = "") const;

    /**
     * A no-args wrapper of print(std::ostream...)
     * meant to be invoked from DPRINTFs
     * avoiding string overheads in fast mode
     * @return string with the request's type and start<->end addresses
     */
    std::string print() const;
};

#endif //__MEM_PACKET_HH
