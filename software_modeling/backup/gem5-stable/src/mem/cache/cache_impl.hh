/*
 * Copyright (c) 2010-2015 ARM Limited
 * All rights reserved.
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
 * Copyright (c) 2002-2005 The Regents of The University of Michigan
 * Copyright (c) 2010,2015 Advanced Micro Devices, Inc.
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
 * Authors: Erik Hallnor
 *          Dave Greene
 *          Nathan Binkert
 *          Steve Reinhardt
 *          Ron Dreslinski
 *          Andreas Sandberg
 */

#ifndef __MEM_CACHE_CACHE_IMPL_HH__
#define __MEM_CACHE_CACHE_IMPL_HH__

/**
 * @file
 * Cache definitions.
 */

#include "base/misc.hh"
#include "base/types.hh"
#include "debug/Cache.hh"
#include "debug/CachePort.hh"
#include "debug/CacheTags.hh"
#include "mem/cache/prefetch/base.hh"
#include "mem/cache/blk.hh"
#include "mem/cache/cache.hh"
#include "mem/cache/mshr.hh"
#include "sim/sim_exit.hh"

Cache::Cache(const Params *p)
    : BaseCache(p),
      tags(p->tags),
      prefetcher(p->prefetcher),
      doFastWrites(true),
      prefetchOnAccess(p->prefetch_on_access)
{
    tempBlock = new CacheBlk();
    tempBlock->data = new uint8_t[blkSize];

    cpuSidePort = new CpuSidePort(p->name + ".cpu_side", this,
                                  "CpuSidePort");
    memSidePort = new MemSidePort(p->name + ".mem_side", this,
                                  "MemSidePort");

    tags->setCache(this);
    if (prefetcher)
        prefetcher->setCache(this);
}

Cache::~Cache()
{
    delete [] tempBlock->data;
    delete tempBlock;

    delete cpuSidePort;
    delete memSidePort;
}

void
Cache::regStats()
{
    BaseCache::regStats();
}

void
Cache::cmpAndSwap(CacheBlk *blk, PacketPtr pkt)
{
    assert(pkt->isRequest());

    uint64_t overwrite_val;
    bool overwrite_mem;
    uint64_t condition_val64;
    uint32_t condition_val32;

    int offset = tags->extractBlkOffset(pkt->getAddr());
    uint8_t *blk_data = blk->data + offset;

    assert(sizeof(uint64_t) >= pkt->getSize());

    overwrite_mem = true;
    // keep a copy of our possible write value, and copy what is at the
    // memory address into the packet
    pkt->writeData((uint8_t *)&overwrite_val);
    pkt->setData(blk_data);

    if (pkt->req->isCondSwap()) {
        if (pkt->getSize() == sizeof(uint64_t)) {
            condition_val64 = pkt->req->getExtraData();
            overwrite_mem = !std::memcmp(&condition_val64, blk_data,
                                         sizeof(uint64_t));
        } else if (pkt->getSize() == sizeof(uint32_t)) {
            condition_val32 = (uint32_t)pkt->req->getExtraData();
            overwrite_mem = !std::memcmp(&condition_val32, blk_data,
                                         sizeof(uint32_t));
        } else
            panic("Invalid size for conditional read/write\n");
    }

    if (overwrite_mem) {
        std::memcpy(blk_data, &overwrite_val, pkt->getSize());
        blk->status |= BlkDirty;
    }
}


void
Cache::satisfyCpuSideRequest(PacketPtr pkt, CacheBlk *blk,
                             bool deferred_response, bool pending_downgrade)
{
    assert(pkt->isRequest());

    assert(blk && blk->isValid());
    // Occasionally this is not true... if we are a lower-level cache
    // satisfying a string of Read and ReadEx requests from
    // upper-level caches, a Read will mark the block as shared but we
    // can satisfy a following ReadEx anyway since we can rely on the
    // Read requester(s) to have buffered the ReadEx snoop and to
    // invalidate their blocks after receiving them.
    // assert(!pkt->needsExclusive() || blk->isWritable());
    assert(pkt->getOffset(blkSize) + pkt->getSize() <= blkSize);

    // Check RMW operations first since both isRead() and
    // isWrite() will be true for them
    if (pkt->cmd == MemCmd::SwapReq) {
        cmpAndSwap(blk, pkt);
    } else if (pkt->isWrite() &&
               (!pkt->isWriteInvalidate() || isTopLevel)) {
        assert(blk->isWritable());
        // Write or WriteInvalidate at the first cache with block in Exclusive
        if (blk->checkWrite(pkt)) {
            pkt->writeDataToBlock(blk->data, blkSize);
        }
        // Always mark the line as dirty even if we are a failed
        // StoreCond so we supply data to any snoops that have
        // appended themselves to this cache before knowing the store
        // will fail.
        blk->status |= BlkDirty;
        DPRINTF(Cache, "%s for %s addr %#llx size %d (write)\n", __func__,
                pkt->cmdString(), pkt->getAddr(), pkt->getSize());
    } else if (pkt->isRead()) {
        if (pkt->isLLSC()) {
            blk->trackLoadLocked(pkt);
        }
        pkt->setDataFromBlock(blk->data, blkSize);
        if (pkt->getSize() == blkSize) {
            // special handling for coherent block requests from
            // upper-level caches
            if (pkt->needsExclusive()) {
                // if we have a dirty copy, make sure the recipient
                // keeps it marked dirty
                if (blk->isDirty()) {
                    pkt->assertMemInhibit();
                }
                // on ReadExReq we give up our copy unconditionally
                if (blk != tempBlock)
                    tags->invalidate(blk);
                blk->invalidate();
            } else if (blk->isWritable() && !pending_downgrade
                      && !pkt->sharedAsserted() && !pkt->req->isInstFetch()) {
                // we can give the requester an exclusive copy (by not
                // asserting shared line) on a read request if:
                // - we have an exclusive copy at this level (& below)
                // - we don't have a pending snoop from below
                //   signaling another read request
                // - no other cache above has a copy (otherwise it
                //   would have asseretd shared line on request)
                // - we are not satisfying an instruction fetch (this
                //   prevents dirty data in the i-cache)

                if (blk->isDirty()) {
                    // special considerations if we're owner:
                    if (!deferred_response && !isTopLevel) {
                        // if we are responding immediately and can
                        // signal that we're transferring ownership
                        // along with exclusivity, do so
                        pkt->assertMemInhibit();
                        blk->status &= ~BlkDirty;
                    } else {
                        // if we're responding after our own miss,
                        // there's a window where the recipient didn't
                        // know it was getting ownership and may not
                        // have responded to snoops correctly, so we
                        // can't pass off ownership *or* exclusivity
                        pkt->assertShared();
                    }
                }
            } else {
                // otherwise only respond with a shared copy
                pkt->assertShared();
            }
        }
    } else {
        // Upgrade or WriteInvalidate at a different cache than received it.
        // Since we have it Exclusively (E or M), we ack then invalidate.
        assert(pkt->isUpgrade() ||
               (pkt->isWriteInvalidate() && !isTopLevel));
        assert(blk != tempBlock);
        tags->invalidate(blk);
        blk->invalidate();
        DPRINTF(Cache, "%s for %s addr %#llx size %d (invalidation)\n",
                __func__, pkt->cmdString(), pkt->getAddr(), pkt->getSize());
    }
}


/////////////////////////////////////////////////////
//
// MSHR helper functions
//
/////////////////////////////////////////////////////


void
Cache::markInService(MSHR *mshr, bool pending_dirty_resp)
{
    markInServiceInternal(mshr, pending_dirty_resp);
#if 0
        if (mshr->originalCmd == MemCmd::HardPFReq) {
            DPRINTF(HWPrefetch, "Marking a HW_PF in service\n");
            //Also clear pending if need be
            if (!prefetcher->havePending())
            {
                deassertMemSideBusRequest(Request_PF);
            }
        }
#endif
}


void
Cache::squash(int threadNum)
{
    bool unblock = false;
    BlockedCause cause = NUM_BLOCKED_CAUSES;

    if (noTargetMSHR && noTargetMSHR->threadNum == threadNum) {
        noTargetMSHR = NULL;
        unblock = true;
        cause = Blocked_NoTargets;
    }
    if (mshrQueue.isFull()) {
        unblock = true;
        cause = Blocked_NoMSHRs;
    }
    mshrQueue.squash(threadNum);
    if (unblock && !mshrQueue.isFull()) {
        clearBlocked(cause);
    }
}

/////////////////////////////////////////////////////
//
// Access path: requests coming in from the CPU side
//
/////////////////////////////////////////////////////

bool
Cache::access(PacketPtr pkt, CacheBlk *&blk, Cycles &lat,
              PacketList &writebacks)
{
    // sanity check
    assert(pkt->isRequest());

    DPRINTF(Cache, "%s for %s addr %#llx size %d\n", __func__,
            pkt->cmdString(), pkt->getAddr(), pkt->getSize());
    if (pkt->req->isUncacheable()) {
        DPRINTF(Cache, "%s%s addr %#llx uncacheable\n", pkt->cmdString(),
                pkt->req->isInstFetch() ? " (ifetch)" : "",
                pkt->getAddr());

        if (pkt->req->isClearLL())
            tags->clearLocks();

        // flush and invalidate any existing block
        CacheBlk *old_blk(tags->findBlock(pkt->getAddr(), pkt->isSecure()));
        if (old_blk && old_blk->isValid()) {
            if (old_blk->isDirty())
                writebacks.push_back(writebackBlk(old_blk));
            tags->invalidate(old_blk);
            old_blk->invalidate();
        }

        blk = NULL;
        // lookupLatency is the latency in case the request is uncacheable.
        lat = lookupLatency;
        return false;
    }

    int id = pkt->req->hasContextId() ? pkt->req->contextId() : -1;
    // Here lat is the value passed as parameter to accessBlock() function
    // that can modify its value.
    blk = tags->accessBlock(pkt->getAddr(), pkt->isSecure(), lat, id);

    DPRINTF(Cache, "%s%s addr %#llx size %d (%s) %s\n", pkt->cmdString(),
            pkt->req->isInstFetch() ? " (ifetch)" : "",
            pkt->getAddr(), pkt->getSize(), pkt->isSecure() ? "s" : "ns",
            blk ? "hit " + blk->print() : "miss");

    // Writeback handling is special case.  We can write the block into
    // the cache without having a writeable copy (or any copy at all).
    if (pkt->cmd == MemCmd::Writeback) {
        assert(blkSize == pkt->getSize());
        if (blk == NULL) {
            // need to do a replacement
            blk = allocateBlock(pkt->getAddr(), pkt->isSecure(), writebacks);
            if (blk == NULL) {
                // no replaceable block available: give up, fwd to next level.
                incMissCount(pkt);
                return false;
            }
            tags->insertBlock(pkt, blk);

            blk->status = (BlkValid | BlkReadable);
            if (pkt->isSecure()) {
                blk->status |= BlkSecure;
            }
        }
        blk->status |= BlkDirty;
        if (pkt->isSupplyExclusive()) {
            blk->status |= BlkWritable;
        }
        // nothing else to do; writeback doesn't expect response
        assert(!pkt->needsResponse());
        std::memcpy(blk->data, pkt->getConstPtr<uint8_t>(), blkSize);
        DPRINTF(Cache, "%s new state is %s\n", __func__, blk->print());
        incHitCount(pkt);
        return true;
    } else if ((blk != NULL) &&
               (pkt->needsExclusive() ? blk->isWritable()
                                      : blk->isReadable())) {
        // OK to satisfy access
        incHitCount(pkt);
        satisfyCpuSideRequest(pkt, blk);
        return true;
    }

    // Can't satisfy access normally... either no block (blk == NULL)
    // or have block but need exclusive & only have shared.

    incMissCount(pkt);

    if (blk == NULL && pkt->isLLSC() && pkt->isWrite()) {
        // complete miss on store conditional... just give up now
        pkt->req->setExtraData(0);
        return true;
    }

    return false;
}


class ForwardResponseRecord : public Packet::SenderState
{
  public:

    ForwardResponseRecord() {}
};

void
Cache::recvTimingSnoopResp(PacketPtr pkt)
{
    DPRINTF(Cache, "%s for %s addr %#llx size %d\n", __func__,
            pkt->cmdString(), pkt->getAddr(), pkt->getSize());

    assert(pkt->isResponse());

    // must be cache-to-cache response from upper to lower level
    ForwardResponseRecord *rec =
        dynamic_cast<ForwardResponseRecord *>(pkt->senderState);
    assert(!system->bypassCaches());

    if (rec == NULL) {
        // @todo What guarantee do we have that this HardPFResp is
        // actually for this cache, and not a cache closer to the
        // memory?
        assert(pkt->cmd == MemCmd::HardPFResp);
        // Check if it's a prefetch response and handle it. We shouldn't
        // get any other kinds of responses without FRRs.
        DPRINTF(Cache, "Got prefetch response from above for addr %#llx (%s)\n",
                pkt->getAddr(), pkt->isSecure() ? "s" : "ns");
        recvTimingResp(pkt);
        return;
    }

    pkt->popSenderState();
    delete rec;
    // forwardLatency is set here because there is a response from an
    // upper level cache.
    // To pay the delay that occurs if the packet comes from the bus,
    // we charge also headerDelay.
    Tick snoop_resp_time = clockEdge(forwardLatency) + pkt->headerDelay;
    // Reset the timing of the packet.
    pkt->headerDelay = pkt->payloadDelay = 0;
    memSidePort->schedTimingSnoopResp(pkt, snoop_resp_time);
}

void
Cache::promoteWholeLineWrites(PacketPtr pkt)
{
    // Cache line clearing instructions
    if (doFastWrites && (pkt->cmd == MemCmd::WriteReq) &&
        (pkt->getSize() == blkSize) && (pkt->getOffset(blkSize) == 0)) {
        pkt->cmd = MemCmd::WriteInvalidateReq;
        DPRINTF(Cache, "packet promoted from Write to WriteInvalidate\n");
        assert(isTopLevel); // should only happen at L1 or I/O cache
    }
}

bool
Cache::recvTimingReq(PacketPtr pkt)
{
    DPRINTF(CacheTags, "%s tags: %s\n", __func__, tags->print());
//@todo Add back in MemDebug Calls
//    MemDebug::cacheAccess(pkt);


    /// @todo temporary hack to deal with memory corruption issue until
    /// 4-phase transactions are complete
    for (int x = 0; x < pendingDelete.size(); x++)
        delete pendingDelete[x];
    pendingDelete.clear();

    assert(pkt->isRequest());

    // Just forward the packet if caches are disabled.
    if (system->bypassCaches()) {
        // @todo This should really enqueue the packet rather
        bool M5_VAR_USED success = memSidePort->sendTimingReq(pkt);
        assert(success);
        return true;
    }

    promoteWholeLineWrites(pkt);

    if (pkt->memInhibitAsserted()) {
        // a cache above us (but not where the packet came from) is
        // responding to the request
        DPRINTF(Cache, "mem inhibited on addr %#llx (%s): not responding\n",
                pkt->getAddr(), pkt->isSecure() ? "s" : "ns");

        // if the packet needs exclusive, and the cache that has
        // promised to respond (setting the inhibit flag) is not
        // providing exclusive (it is in O vs M state), we know that
        // there may be other shared copies in the system; go out and
        // invalidate them all
        if (pkt->needsExclusive() && !pkt->isSupplyExclusive()) {
            // create a downstream express snoop with cleared packet
            // flags, there is no need to allocate any data as the
            // packet is merely used to co-ordinate state transitions
            Packet *snoop_pkt = new Packet(pkt, true, false);

            // also reset the bus time that the original packet has
            // not yet paid for
            snoop_pkt->headerDelay = snoop_pkt->payloadDelay = 0;

            // make this an instantaneous express snoop, and let the
            // other caches in the system know that the packet is
            // inhibited, because we have found the authorative copy
            // (O) that will supply the right data
            snoop_pkt->setExpressSnoop();
            snoop_pkt->assertMemInhibit();

            // this express snoop travels towards the memory, and at
            // every crossbar it is snooped upwards thus reaching
            // every cache in the system
            bool M5_VAR_USED success = memSidePort->sendTimingReq(snoop_pkt);
            // express snoops always succeed
            assert(success);

            // main memory will delete the packet
        }

        /// @todo nominally we should just delete the packet here,
        /// however, until 4-phase stuff we can't because sending
        /// cache is still relying on it
        pendingDelete.push_back(pkt);

        // no need to take any action in this particular cache as the
        // caches along the path to memory are allowed to keep lines
        // in a shared state, and a cache above us already committed
        // to responding
        return true;
    }

    // anything that is merely forwarded pays for the forward latency and
    // the delay provided by the crossbar
    Tick forward_time = clockEdge(forwardLatency) + pkt->headerDelay;

    // We use lookupLatency here because it is used to specify the latency
    // to access.
    Cycles lat = lookupLatency;
    CacheBlk *blk = NULL;
    bool satisfied = false;
    {
        PacketList writebacks;
        // Note that lat is passed by reference here. The function
        // access() calls accessBlock() which can modify lat value.
        satisfied = access(pkt, blk, lat, writebacks);

        // copy writebacks to write buffer here to ensure they logically
        // proceed anything happening below
        while (!writebacks.empty()) {
            PacketPtr wbPkt = writebacks.front();
            // We use forwardLatency here because we are copying
            // writebacks to write buffer.
            allocateWriteBuffer(wbPkt, forward_time, true);
            writebacks.pop_front();
        }
    }

    // Here we charge the headerDelay that takes into account the latencies
    // of the bus, if the packet comes from it.
    // The latency charged it is just lat that is the value of lookupLatency
    // modified by access() function, or if not just lookupLatency.
    // In case of a hit we are neglecting response latency.
    // In case of a miss we are neglecting forward latency.
    Tick request_time = clockEdge(lat) + pkt->headerDelay;
    // Here we reset the timing of the packet.
    pkt->headerDelay = pkt->payloadDelay = 0;

    // track time of availability of next prefetch, if any
    Tick next_pf_time = MaxTick;

    bool needsResponse = pkt->needsResponse();

    if (satisfied) {
        // should never be satisfying an uncacheable access as we
        // flush and invalidate any existing block as part of the
        // lookup
        assert(!pkt->req->isUncacheable());

        // hit (for all other request types)

        if (prefetcher && (prefetchOnAccess || (blk && blk->wasPrefetched()))) {
            if (blk)
                blk->status &= ~BlkHWPrefetched;

            // Don't notify on SWPrefetch
            if (!pkt->cmd.isSWPrefetch())
                next_pf_time = prefetcher->notify(pkt);
        }

        if (needsResponse) {
            pkt->makeTimingResponse();
            // @todo: Make someone pay for this
            pkt->headerDelay = pkt->payloadDelay = 0;

            // In this case we are considering request_time that takes
            // into account the delay of the xbar, if any, and just
            // lat, neglecting responseLatency, modelling hit latency
            // just as lookupLatency or or the value of lat overriden
            // by access(), that calls accessBlock() function.
            cpuSidePort->schedTimingResp(pkt, request_time);
        } else {
            /// @todo nominally we should just delete the packet here,
            /// however, until 4-phase stuff we can't because sending
            /// cache is still relying on it
            pendingDelete.push_back(pkt);
        }
    } else {
        // miss

        Addr blk_addr = blockAlign(pkt->getAddr());

        // ignore any existing MSHR if we are dealing with an
        // uncacheable request
        MSHR *mshr = pkt->req->isUncacheable() ? nullptr :
            mshrQueue.findMatch(blk_addr, pkt->isSecure());

        // Software prefetch handling:
        // To keep the core from waiting on data it won't look at
        // anyway, send back a response with dummy data. Miss handling
        // will continue asynchronously. Unfortunately, the core will
        // insist upon freeing original Packet/Request, so we have to
        // create a new pair with a different lifecycle. Note that this
        // processing happens before any MSHR munging on the behalf of
        // this request because this new Request will be the one stored
        // into the MSHRs, not the original.
        if (pkt->cmd.isSWPrefetch() && isTopLevel) {
            assert(needsResponse);
            assert(pkt->req->hasPaddr());
            assert(!pkt->req->isUncacheable());

            // There's no reason to add a prefetch as an additional target
            // to an existing MSHR. If an outstanding request is already
            // in progress, there is nothing for the prefetch to do.
            // If this is the case, we don't even create a request at all.
            PacketPtr pf = nullptr;

            if (!mshr) {
                // copy the request and create a new SoftPFReq packet
                RequestPtr req = new Request(pkt->req->getPaddr(),
                                             pkt->req->getSize(),
                                             pkt->req->getFlags(),
                                             pkt->req->masterId());
                pf = new Packet(req, pkt->cmd);
                pf->allocate();
                assert(pf->getAddr() == pkt->getAddr());
                assert(pf->getSize() == pkt->getSize());
            }

            pkt->makeTimingResponse();
            // for debugging, set all the bits in the response data
            // (also keeps valgrind from complaining when debugging settings
            //  print out instruction results)
            std::memset(pkt->getPtr<uint8_t>(), 0xFF, pkt->getSize());
            // request_time is used here, taking into account lat and the delay
            // charged if the packet comes from the xbar.
            cpuSidePort->schedTimingResp(pkt, request_time);

            // If an outstanding request is in progress (we found an
            // MSHR) this is set to null
            pkt = pf;
        }

        if (mshr) {
            /// MSHR hit
            /// @note writebacks will be checked in getNextMSHR()
            /// for any conflicting requests to the same block

            //@todo remove hw_pf here

            // Coalesce unless it was a software prefetch (see above).
            if (pkt) {
                DPRINTF(Cache, "%s coalescing MSHR for %s addr %#llx size %d\n",
                        __func__, pkt->cmdString(), pkt->getAddr(),
                        pkt->getSize());

                assert(pkt->req->masterId() < system->maxMasters());
                mshr_hits[pkt->cmdToIndex()][pkt->req->masterId()]++;
                if (mshr->threadNum != 0/*pkt->req->threadId()*/) {
                    mshr->threadNum = -1;
                }
                // We use forward_time here because it is the same
                // considering new targets. We have multiple requests for the
                // same address here. It specifies the latency to allocate an
                // internal buffer and to schedule an event to the queued
                // port and also takes into account the additional delay of
                // the xbar.
                mshr->allocateTarget(pkt, forward_time, order++);
                if (mshr->getNumTargets() == numTarget) {
                    noTargetMSHR = mshr;
                    setBlocked(Blocked_NoTargets);
                    // need to be careful with this... if this mshr isn't
                    // ready yet (i.e. time > curTick()), we don't want to
                    // move it ahead of mshrs that are ready
                    // mshrQueue.moveToFront(mshr);
                }

                // We should call the prefetcher reguardless if the request is
                // satisfied or not, reguardless if the request is in the MSHR or
                // not.  The request could be a ReadReq hit, but still not
                // satisfied (potentially because of a prior write to the same
                // cache line.  So, even when not satisfied, tehre is an MSHR
                // already allocated for this, we need to let the prefetcher know
                // about the request
                if (prefetcher) {
                    // Don't notify on SWPrefetch
                    if (!pkt->cmd.isSWPrefetch())
                        next_pf_time = prefetcher->notify(pkt);
                }
            }
        } else {
            // no MSHR
            assert(pkt->req->masterId() < system->maxMasters());
            if (pkt->req->isUncacheable()) {
                mshr_uncacheable[pkt->cmdToIndex()][pkt->req->masterId()]++;
            } else {
                mshr_misses[pkt->cmdToIndex()][pkt->req->masterId()]++;
            }

            if (pkt->cmd == MemCmd::Writeback ||
                (pkt->req->isUncacheable() && pkt->isWrite())) {
                // We use forward_time here because there is an
                // uncached memory write, forwarded to WriteBuffer. It
                // specifies the latency to allocate an internal buffer and to
                // schedule an event to the queued port and also takes into
                // account the additional delay of the xbar.
                allocateWriteBuffer(pkt, forward_time, true);
            } else {
                if (blk && blk->isValid()) {
                    // should have flushed and have no valid block
                    assert(!pkt->req->isUncacheable());

                    // If we have a write miss to a valid block, we
                    // need to mark the block non-readable.  Otherwise
                    // if we allow reads while there's an outstanding
                    // write miss, the read could return stale data
                    // out of the cache block... a more aggressive
                    // system could detect the overlap (if any) and
                    // forward data out of the MSHRs, but we don't do
                    // that yet.  Note that we do need to leave the
                    // block valid so that it stays in the cache, in
                    // case we get an upgrade response (and hence no
                    // new data) when the write miss completes.
                    // As long as CPUs do proper store/load forwarding
                    // internally, and have a sufficiently weak memory
                    // model, this is probably unnecessary, but at some
                    // point it must have seemed like we needed it...
                    assert(pkt->needsExclusive());
                    assert(!blk->isWritable());
                    blk->status &= ~BlkReadable;
                }
                // Here we are using forward_time, modelling the latency of
                // a miss (outbound) just as forwardLatency, neglecting the
                // lookupLatency component. In this case this latency value
                // specifies the latency to allocate an internal buffer and to
                // schedule an event to the queued port, when a cacheable miss
                // is forwarded to MSHR queue.
                // We take also into account the additional delay of the xbar.
                allocateMissBuffer(pkt, forward_time, true);
            }

            if (prefetcher) {
                // Don't notify on SWPrefetch
                if (!pkt->cmd.isSWPrefetch())
                    next_pf_time = prefetcher->notify(pkt);
            }
        }
    }
    // Here we condiser just forward_time.
    if (next_pf_time != MaxTick)
        requestMemSideBus(Request_PF, std::max(clockEdge(forwardLatency),
                                                next_pf_time));

    return true;
}


// See comment in cache.hh.
PacketPtr
Cache::getBusPacket(PacketPtr cpu_pkt, CacheBlk *blk,
                    bool needsExclusive) const
{
    bool blkValid = blk && blk->isValid();

    if (cpu_pkt->req->isUncacheable()) {
        // note that at the point we see the uncacheable request we
        // flush any block, but there could be an outstanding MSHR,
        // and the cache could have filled again before we actually
        // send out the forwarded uncacheable request (blk could thus
        // be non-null)
        return NULL;
    }

    if (!blkValid &&
        (cpu_pkt->cmd == MemCmd::Writeback || cpu_pkt->isUpgrade())) {
        // Writebacks that weren't allocated in access() and upgrades
        // from upper-level caches that missed completely just go
        // through.
        return NULL;
    }

    assert(cpu_pkt->needsResponse());

    MemCmd cmd;
    // @TODO make useUpgrades a parameter.
    // Note that ownership protocols require upgrade, otherwise a
    // write miss on a shared owned block will generate a ReadExcl,
    // which will clobber the owned copy.
    const bool useUpgrades = true;
    if (blkValid && useUpgrades) {
        // only reason to be here is that blk is shared
        // (read-only) and we need exclusive
        assert(needsExclusive);
        assert(!blk->isWritable());
        cmd = cpu_pkt->isLLSC() ? MemCmd::SCUpgradeReq : MemCmd::UpgradeReq;
    } else if (cpu_pkt->cmd == MemCmd::SCUpgradeFailReq ||
               cpu_pkt->cmd == MemCmd::StoreCondFailReq) {
        // Even though this SC will fail, we still need to send out the
        // request and get the data to supply it to other snoopers in the case
        // where the determination the StoreCond fails is delayed due to
        // all caches not being on the same local bus.
        cmd = MemCmd::SCUpgradeFailReq;
    } else if (cpu_pkt->isWriteInvalidate()) {
        cmd = cpu_pkt->cmd;
    } else {
        // block is invalid
        cmd = needsExclusive ? MemCmd::ReadExReq : MemCmd::ReadReq;
    }
    PacketPtr pkt = new Packet(cpu_pkt->req, cmd, blkSize);

    // if there are sharers in the upper levels, pass that info downstream
    if (cpu_pkt->sharedAsserted()) {
        // note that cpu_pkt may have spent a considerable time in the
        // MSHR queue and that the information could possibly be out
        // of date, however, there is no harm in conservatively
        // assuming the block is shared
        pkt->assertShared();
        DPRINTF(Cache, "%s passing shared from %s to %s addr %#llx size %d\n",
                __func__, cpu_pkt->cmdString(), pkt->cmdString(),
                pkt->getAddr(), pkt->getSize());
    }

    // the packet should be block aligned
    assert(pkt->getAddr() == blockAlign(pkt->getAddr()));

    pkt->allocate();
    DPRINTF(Cache, "%s created %s addr %#llx size %d\n",
            __func__, pkt->cmdString(), pkt->getAddr(), pkt->getSize());
    return pkt;
}


Tick
Cache::recvAtomic(PacketPtr pkt)
{
    // We are in atomic mode so we pay just for lookupLatency here.
    Cycles lat = lookupLatency;
    // @TODO: make this a parameter
    bool last_level_cache = false;

    // Forward the request if the system is in cache bypass mode.
    if (system->bypassCaches())
        return ticksToCycles(memSidePort->sendAtomic(pkt));

    promoteWholeLineWrites(pkt);

    if (pkt->memInhibitAsserted()) {
        // have to invalidate ourselves and any lower caches even if
        // upper cache will be responding
        if (pkt->isInvalidate()) {
            CacheBlk *blk = tags->findBlock(pkt->getAddr(), pkt->isSecure());
            if (blk && blk->isValid()) {
                tags->invalidate(blk);
                blk->invalidate();
                DPRINTF(Cache, "rcvd mem-inhibited %s on %#llx (%s):"
                        " invalidating\n",
                        pkt->cmdString(), pkt->getAddr(),
                        pkt->isSecure() ? "s" : "ns");
            }
            if (!last_level_cache) {
                DPRINTF(Cache, "forwarding mem-inhibited %s on %#llx (%s)\n",
                        pkt->cmdString(), pkt->getAddr(),
                        pkt->isSecure() ? "s" : "ns");
                lat += ticksToCycles(memSidePort->sendAtomic(pkt));
            }
        } else {
            DPRINTF(Cache, "rcvd mem-inhibited %s on %#llx: not responding\n",
                    pkt->cmdString(), pkt->getAddr());
        }

        return lat * clockPeriod();
    }

    // should assert here that there are no outstanding MSHRs or
    // writebacks... that would mean that someone used an atomic
    // access in timing mode

    CacheBlk *blk = NULL;
    PacketList writebacks;
    bool satisfied = access(pkt, blk, lat, writebacks);

    // handle writebacks resulting from the access here to ensure they
    // logically proceed anything happening below
    while (!writebacks.empty()){
        PacketPtr wbPkt = writebacks.front();
        memSidePort->sendAtomic(wbPkt);
        writebacks.pop_front();
        delete wbPkt;
    }

    if (!satisfied) {
        // MISS

        PacketPtr bus_pkt = getBusPacket(pkt, blk, pkt->needsExclusive());

        bool is_forward = (bus_pkt == NULL);

        if (is_forward) {
            // just forwarding the same request to the next level
            // no local cache operation involved
            bus_pkt = pkt;
        }

        DPRINTF(Cache, "Sending an atomic %s for %#llx (%s)\n",
                bus_pkt->cmdString(), bus_pkt->getAddr(),
                bus_pkt->isSecure() ? "s" : "ns");

#if TRACING_ON
        CacheBlk::State old_state = blk ? blk->status : 0;
#endif

        lat += ticksToCycles(memSidePort->sendAtomic(bus_pkt));

        // We are now dealing with the response handling
        DPRINTF(Cache, "Receive response: %s for addr %#llx (%s) in state %i\n",
                bus_pkt->cmdString(), bus_pkt->getAddr(),
                bus_pkt->isSecure() ? "s" : "ns",
                old_state);

        // If packet was a forward, the response (if any) is already
        // in place in the bus_pkt == pkt structure, so we don't need
        // to do anything.  Otherwise, use the separate bus_pkt to
        // generate response to pkt and then delete it.
        if (!is_forward) {
            if (pkt->needsResponse()) {
                assert(bus_pkt->isResponse());
                if (bus_pkt->isError()) {
                    pkt->makeAtomicResponse();
                    pkt->copyError(bus_pkt);
                } else if (pkt->isWriteInvalidate()) {
                    // note the use of pkt, not bus_pkt here.
                    if (isTopLevel) {
                        blk = handleFill(pkt, blk, writebacks);
                        satisfyCpuSideRequest(pkt, blk);
                    } else if (blk) {
                        satisfyCpuSideRequest(pkt, blk);
                    }
                } else if (bus_pkt->isRead() ||
                           bus_pkt->cmd == MemCmd::UpgradeResp) {
                    // we're updating cache state to allow us to
                    // satisfy the upstream request from the cache
                    blk = handleFill(bus_pkt, blk, writebacks);
                    satisfyCpuSideRequest(pkt, blk);
                } else {
                    // we're satisfying the upstream request without
                    // modifying cache state, e.g., a write-through
                    pkt->makeAtomicResponse();
                }
            }
            delete bus_pkt;
        }
    }

    // Note that we don't invoke the prefetcher at all in atomic mode.
    // It's not clear how to do it properly, particularly for
    // prefetchers that aggressively generate prefetch candidates and
    // rely on bandwidth contention to throttle them; these will tend
    // to pollute the cache in atomic mode since there is no bandwidth
    // contention.  If we ever do want to enable prefetching in atomic
    // mode, though, this is the place to do it... see timingAccess()
    // for an example (though we'd want to issue the prefetch(es)
    // immediately rather than calling requestMemSideBus() as we do
    // there).

    // Handle writebacks (from the response handling) if needed
    while (!writebacks.empty()){
        PacketPtr wbPkt = writebacks.front();
        memSidePort->sendAtomic(wbPkt);
        writebacks.pop_front();
        delete wbPkt;
    }

    if (pkt->needsResponse()) {
        pkt->makeAtomicResponse();
    }

    return lat * clockPeriod();
}


void
Cache::functionalAccess(PacketPtr pkt, bool fromCpuSide)
{
    if (system->bypassCaches()) {
        // Packets from the memory side are snoop request and
        // shouldn't happen in bypass mode.
        assert(fromCpuSide);

        // The cache should be flushed if we are in cache bypass mode,
        // so we don't need to check if we need to update anything.
        memSidePort->sendFunctional(pkt);
        return;
    }

    Addr blk_addr = blockAlign(pkt->getAddr());
    bool is_secure = pkt->isSecure();
    CacheBlk *blk = tags->findBlock(pkt->getAddr(), is_secure);
    MSHR *mshr = mshrQueue.findMatch(blk_addr, is_secure);

    pkt->pushLabel(name());

    CacheBlkPrintWrapper cbpw(blk);

    // Note that just because an L2/L3 has valid data doesn't mean an
    // L1 doesn't have a more up-to-date modified copy that still
    // needs to be found.  As a result we always update the request if
    // we have it, but only declare it satisfied if we are the owner.

    // see if we have data at all (owned or otherwise)
    bool have_data = blk && blk->isValid()
        && pkt->checkFunctional(&cbpw, blk_addr, is_secure, blkSize,
                                blk->data);

    // data we have is dirty if marked as such or if valid & ownership
    // pending due to outstanding UpgradeReq
    bool have_dirty =
        have_data && (blk->isDirty() ||
                      (mshr && mshr->inService && mshr->isPendingDirty()));

    bool done = have_dirty
        || cpuSidePort->checkFunctional(pkt)
        || mshrQueue.checkFunctional(pkt, blk_addr)
        || writeBuffer.checkFunctional(pkt, blk_addr)
        || memSidePort->checkFunctional(pkt);

    DPRINTF(Cache, "functional %s %#llx (%s) %s%s%s\n",
            pkt->cmdString(), pkt->getAddr(), is_secure ? "s" : "ns",
            (blk && blk->isValid()) ? "valid " : "",
            have_data ? "data " : "", done ? "done " : "");

    // We're leaving the cache, so pop cache->name() label
    pkt->popLabel();

    if (done) {
        pkt->makeResponse();
    } else {
        // if it came as a request from the CPU side then make sure it
        // continues towards the memory side
        if (fromCpuSide) {
            memSidePort->sendFunctional(pkt);
        } else if (forwardSnoops && cpuSidePort->isSnooping()) {
            // if it came from the memory side, it must be a snoop request
            // and we should only forward it if we are forwarding snoops
            cpuSidePort->sendFunctionalSnoop(pkt);
        }
    }
}


/////////////////////////////////////////////////////
//
// Response handling: responses from the memory side
//
/////////////////////////////////////////////////////


void
Cache::recvTimingResp(PacketPtr pkt)
{
    assert(pkt->isResponse());

    MSHR *mshr = dynamic_cast<MSHR*>(pkt->senderState);
    bool is_error = pkt->isError();

    assert(mshr);

    if (is_error) {
        DPRINTF(Cache, "Cache received packet with error for addr %#llx (%s), "
                "cmd: %s\n", pkt->getAddr(), pkt->isSecure() ? "s" : "ns",
                pkt->cmdString());
    }

    DPRINTF(Cache, "Handling response %s for addr %#llx size %d (%s)\n",
            pkt->cmdString(), pkt->getAddr(), pkt->getSize(),
            pkt->isSecure() ? "s" : "ns");

    MSHRQueue *mq = mshr->queue;
    bool wasFull = mq->isFull();

    if (mshr == noTargetMSHR) {
        // we always clear at least one target
        clearBlocked(Blocked_NoTargets);
        noTargetMSHR = NULL;
    }

    // Initial target is used just for stats
    MSHR::Target *initial_tgt = mshr->getTarget();
    CacheBlk *blk = tags->findBlock(pkt->getAddr(), pkt->isSecure());
    int stats_cmd_idx = initial_tgt->pkt->cmdToIndex();
    Tick miss_latency = curTick() - initial_tgt->recvTime;
    PacketList writebacks;
    // We need forward_time here because we have a call of
    // allocateWriteBuffer() that need this parameter to specify the
    // time to request the bus.  In this case we use forward latency
    // because there is a writeback.  We pay also here for headerDelay
    // that is charged of bus latencies if the packet comes from the
    // bus.
    Tick forward_time = clockEdge(forwardLatency) + pkt->headerDelay;

    if (pkt->req->isUncacheable()) {
        assert(pkt->req->masterId() < system->maxMasters());
        mshr_uncacheable_lat[stats_cmd_idx][pkt->req->masterId()] +=
            miss_latency;
    } else {
        assert(pkt->req->masterId() < system->maxMasters());
        mshr_miss_latency[stats_cmd_idx][pkt->req->masterId()] +=
            miss_latency;
    }

    bool is_fill = !mshr->isForward &&
        (pkt->isRead() || pkt->cmd == MemCmd::UpgradeResp);

    if (is_fill && !is_error) {
        DPRINTF(Cache, "Block for addr %#llx being updated in Cache\n",
                pkt->getAddr());

        // give mshr a chance to do some dirty work
        mshr->handleFill(pkt, blk);

        blk = handleFill(pkt, blk, writebacks);
        assert(blk != NULL);
    }

    // First offset for critical word first calculations
    int initial_offset = initial_tgt->pkt->getOffset(blkSize);

    while (mshr->hasTargets()) {
        MSHR::Target *target = mshr->getTarget();
        Packet *tgt_pkt = target->pkt;

        switch (target->source) {
          case MSHR::Target::FromCPU:
            Tick completion_time;
            // Here we charge on completion_time the delay of the xbar if the
            // packet comes from it, charged on headerDelay.
            completion_time = pkt->headerDelay;

            // Software prefetch handling for cache closest to core
            if (tgt_pkt->cmd.isSWPrefetch() && isTopLevel) {
                // a software prefetch would have already been ack'd immediately
                // with dummy data so the core would be able to retire it.
                // this request completes right here, so we deallocate it.
                delete tgt_pkt->req;
                delete tgt_pkt;
                break; // skip response
            }

            // unlike the other packet flows, where data is found in other
            // caches or memory and brought back, write invalidates always
            // have the data right away, so the above check for "is fill?"
            // cannot actually be determined until examining the stored MSHR
            // state. We "catch up" with that logic here, which is duplicated
            // from above.
            if (tgt_pkt->isWriteInvalidate() && isTopLevel) {
                assert(!is_error);

                // NB: we use the original packet here and not the response!
                mshr->handleFill(tgt_pkt, blk);
                blk = handleFill(tgt_pkt, blk, writebacks);
                assert(blk != NULL);

                is_fill = true;
            }

            if (is_fill) {
                satisfyCpuSideRequest(tgt_pkt, blk,
                                      true, mshr->hasPostDowngrade());

                // How many bytes past the first request is this one
                int transfer_offset =
                    tgt_pkt->getOffset(blkSize) - initial_offset;
                if (transfer_offset < 0) {
                    transfer_offset += blkSize;
                }

                // If not critical word (offset) return payloadDelay.
                // responseLatency is the latency of the return path
                // from lower level caches/memory to an upper level cache or
                // the core.
                completion_time += clockEdge(responseLatency) +
                    (transfer_offset ? pkt->payloadDelay : 0);

                assert(!tgt_pkt->req->isUncacheable());

                assert(tgt_pkt->req->masterId() < system->maxMasters());
                missLatency[tgt_pkt->cmdToIndex()][tgt_pkt->req->masterId()] +=
                    completion_time - target->recvTime;
            } else if (pkt->cmd == MemCmd::UpgradeFailResp) {
                // failed StoreCond upgrade
                assert(tgt_pkt->cmd == MemCmd::StoreCondReq ||
                       tgt_pkt->cmd == MemCmd::StoreCondFailReq ||
                       tgt_pkt->cmd == MemCmd::SCUpgradeFailReq);
                // responseLatency is the latency of the return path
                // from lower level caches/memory to an upper level cache or
                // the core.
                completion_time += clockEdge(responseLatency) +
                    pkt->payloadDelay;
                tgt_pkt->req->setExtraData(0);
            } else {
                // not a cache fill, just forwarding response
                // responseLatency is the latency of the return path
                // from lower level cahces/memory to the core.
                completion_time += clockEdge(responseLatency) +
                    pkt->payloadDelay;
                if (pkt->isRead() && !is_error) {
                    // sanity check
                    assert(pkt->getAddr() == tgt_pkt->getAddr());
                    assert(pkt->getSize() >= tgt_pkt->getSize());

                    tgt_pkt->setData(pkt->getConstPtr<uint8_t>());
                }
            }
            tgt_pkt->makeTimingResponse();
            // if this packet is an error copy that to the new packet
            if (is_error)
                tgt_pkt->copyError(pkt);
            if (tgt_pkt->cmd == MemCmd::ReadResp &&
                (pkt->isInvalidate() || mshr->hasPostInvalidate())) {
                // If intermediate cache got ReadRespWithInvalidate,
                // propagate that.  Response should not have
                // isInvalidate() set otherwise.
                tgt_pkt->cmd = MemCmd::ReadRespWithInvalidate;
                DPRINTF(Cache, "%s updated cmd to %s for addr %#llx\n",
                        __func__, tgt_pkt->cmdString(), tgt_pkt->getAddr());
            }
            // Reset the bus additional time as it is now accounted for
            tgt_pkt->headerDelay = tgt_pkt->payloadDelay = 0;
            cpuSidePort->schedTimingResp(tgt_pkt, completion_time);
            break;

          case MSHR::Target::FromPrefetcher:
            assert(tgt_pkt->cmd == MemCmd::HardPFReq);
            if (blk)
                blk->status |= BlkHWPrefetched;
            delete tgt_pkt->req;
            delete tgt_pkt;
            break;

          case MSHR::Target::FromSnoop:
            // I don't believe that a snoop can be in an error state
            assert(!is_error);
            // response to snoop request
            DPRINTF(Cache, "processing deferred snoop...\n");
            assert(!(pkt->isInvalidate() && !mshr->hasPostInvalidate()));
            handleSnoop(tgt_pkt, blk, true, true, mshr->hasPostInvalidate());
            break;

          default:
            panic("Illegal target->source enum %d\n", target->source);
        }

        mshr->popTarget();
    }

    if (blk && blk->isValid()) {
        if ((pkt->isInvalidate() || mshr->hasPostInvalidate()) &&
            (!pkt->isWriteInvalidate() || !isTopLevel)) {
            assert(blk != tempBlock);
            tags->invalidate(blk);
            blk->invalidate();
        } else if (mshr->hasPostDowngrade()) {
            blk->status &= ~BlkWritable;
        }
    }

    if (mshr->promoteDeferredTargets()) {
        // avoid later read getting stale data while write miss is
        // outstanding.. see comment in timingAccess()
        if (blk) {
            blk->status &= ~BlkReadable;
        }
        mq = mshr->queue;
        mq->markPending(mshr);
        requestMemSideBus((RequestCause)mq->index, clockEdge() +
                          pkt->payloadDelay);
    } else {
        mq->deallocate(mshr);
        if (wasFull && !mq->isFull()) {
            clearBlocked((BlockedCause)mq->index);
        }

        // Request the bus for a prefetch if this deallocation freed enough
        // MSHRs for a prefetch to take place
        if (prefetcher && mq == &mshrQueue && mshrQueue.canPrefetch()) {
            Tick next_pf_time = std::max(prefetcher->nextPrefetchReadyTime(),
                                         curTick());
            if (next_pf_time != MaxTick)
                requestMemSideBus(Request_PF, next_pf_time);
        }
    }
    // reset the xbar additional timinig  as it is now accounted for
    pkt->headerDelay = pkt->payloadDelay = 0;

    // copy writebacks to write buffer
    while (!writebacks.empty()) {
        PacketPtr wbPkt = writebacks.front();
        allocateWriteBuffer(wbPkt, clockEdge(forwardLatency), true);
        writebacks.pop_front();
    }
    // if we used temp block, clear it out
    if (blk == tempBlock) {
        if (blk->isDirty()) {
            // We use forwardLatency here because we are copying
            // writebacks to write buffer. It specifies the latency to
            // allocate an internal buffer and to schedule an event to the
            // queued port.
            allocateWriteBuffer(writebackBlk(blk), forward_time, true);
        }
        blk->invalidate();
    }

    DPRINTF(Cache, "Leaving %s with %s for addr %#llx\n", __func__,
            pkt->cmdString(), pkt->getAddr());
    delete pkt;
}

PacketPtr
Cache::writebackBlk(CacheBlk *blk)
{
    assert(blk && blk->isValid() && blk->isDirty());

    writebacks[Request::wbMasterId]++;

    Request *writebackReq =
        new Request(tags->regenerateBlkAddr(blk->tag, blk->set), blkSize, 0,
                Request::wbMasterId);
    if (blk->isSecure())
        writebackReq->setFlags(Request::SECURE);

    writebackReq->taskId(blk->task_id);
    blk->task_id= ContextSwitchTaskId::Unknown;
    blk->tickInserted = curTick();

    PacketPtr writeback = new Packet(writebackReq, MemCmd::Writeback);
    if (blk->isWritable()) {
        writeback->setSupplyExclusive();
    }
    writeback->allocate();
    std::memcpy(writeback->getPtr<uint8_t>(), blk->data, blkSize);

    blk->status &= ~BlkDirty;
    return writeback;
}

void
Cache::memWriteback()
{
    CacheBlkVisitorWrapper visitor(*this, &Cache::writebackVisitor);
    tags->forEachBlk(visitor);
}

void
Cache::memInvalidate()
{
    CacheBlkVisitorWrapper visitor(*this, &Cache::invalidateVisitor);
    tags->forEachBlk(visitor);
}

bool
Cache::isDirty() const
{
    CacheBlkIsDirtyVisitor visitor;
    tags->forEachBlk(visitor);

    return visitor.isDirty();
}

bool
Cache::writebackVisitor(CacheBlk &blk)
{
    if (blk.isDirty()) {
        assert(blk.isValid());

        Request request(tags->regenerateBlkAddr(blk.tag, blk.set),
                        blkSize, 0, Request::funcMasterId);
        request.taskId(blk.task_id);

        Packet packet(&request, MemCmd::WriteReq);
        packet.dataStatic(blk.data);

        memSidePort->sendFunctional(&packet);

        blk.status &= ~BlkDirty;
    }

    return true;
}

bool
Cache::invalidateVisitor(CacheBlk &blk)
{

    if (blk.isDirty())
        warn_once("Invalidating dirty cache lines. Expect things to break.\n");

    if (blk.isValid()) {
        assert(!blk.isDirty());
        tags->invalidate(&blk);
        blk.invalidate();
    }

    return true;
}

CacheBlk*
Cache::allocateBlock(Addr addr, bool is_secure, PacketList &writebacks)
{
    CacheBlk *blk = tags->findVictim(addr);

    if (blk->isValid()) {
        Addr repl_addr = tags->regenerateBlkAddr(blk->tag, blk->set);
        MSHR *repl_mshr = mshrQueue.findMatch(repl_addr, blk->isSecure());
        if (repl_mshr) {
            // must be an outstanding upgrade request
            // on a block we're about to replace...
            assert(!blk->isWritable() || blk->isDirty());
            assert(repl_mshr->needsExclusive());
            // too hard to replace block with transient state
            // allocation failed, block not inserted
            return NULL;
        } else {
            DPRINTF(Cache, "replacement: replacing %#llx (%s) with %#llx (%s): %s\n",
                    repl_addr, blk->isSecure() ? "s" : "ns",
                    addr, is_secure ? "s" : "ns",
                    blk->isDirty() ? "writeback" : "clean");

            if (blk->isDirty()) {
                // Save writeback packet for handling by caller
                writebacks.push_back(writebackBlk(blk));
            }
        }
    }

    return blk;
}


// Note that the reason we return a list of writebacks rather than
// inserting them directly in the write buffer is that this function
// is called by both atomic and timing-mode accesses, and in atomic
// mode we don't mess with the write buffer (we just perform the
// writebacks atomically once the original request is complete).
CacheBlk*
Cache::handleFill(PacketPtr pkt, CacheBlk *blk, PacketList &writebacks)
{
    assert(pkt->isResponse() || pkt->isWriteInvalidate());
    Addr addr = pkt->getAddr();
    bool is_secure = pkt->isSecure();
#if TRACING_ON
    CacheBlk::State old_state = blk ? blk->status : 0;
#endif

    if (blk == NULL) {
        // better have read new data...
        assert(pkt->hasData());

        // only read responses and (original) write invalidate req's have data;
        // note that we don't write the data here for write invalidate - that
        // happens in the subsequent satisfyCpuSideRequest.
        assert(pkt->isRead() || pkt->isWriteInvalidate());

        // need to do a replacement
        blk = allocateBlock(addr, is_secure, writebacks);
        if (blk == NULL) {
            // No replaceable block... just use temporary storage to
            // complete the current request and then get rid of it
            assert(!tempBlock->isValid());
            blk = tempBlock;
            tempBlock->set = tags->extractSet(addr);
            tempBlock->tag = tags->extractTag(addr);
            // @todo: set security state as well...
            DPRINTF(Cache, "using temp block for %#llx (%s)\n", addr,
                    is_secure ? "s" : "ns");
        } else {
            tags->insertBlock(pkt, blk);
        }

        // we should never be overwriting a valid block
        assert(!blk->isValid());
    } else {
        // existing block... probably an upgrade
        assert(blk->tag == tags->extractTag(addr));
        // either we're getting new data or the block should already be valid
        assert(pkt->hasData() || blk->isValid());
        // don't clear block status... if block is already dirty we
        // don't want to lose that
    }

    if (is_secure)
        blk->status |= BlkSecure;
    blk->status |= BlkValid | BlkReadable;

    if (!pkt->sharedAsserted()) {
        blk->status |= BlkWritable;
        // If we got this via cache-to-cache transfer (i.e., from a
        // cache that was an owner) and took away that owner's copy,
        // then we need to write it back.  Normally this happens
        // anyway as a side effect of getting a copy to write it, but
        // there are cases (such as failed store conditionals or
        // compare-and-swaps) where we'll demand an exclusive copy but
        // end up not writing it.
        if (pkt->memInhibitAsserted())
            blk->status |= BlkDirty;
    }

    DPRINTF(Cache, "Block addr %#llx (%s) moving from state %x to %s\n",
            addr, is_secure ? "s" : "ns", old_state, blk->print());

    // if we got new data, copy it in (checking for a read response
    // and a response that has data is the same in the end)
    if (pkt->isRead()) {
        // sanity checks
        assert(pkt->hasData());
        assert(pkt->getSize() == blkSize);

        std::memcpy(blk->data, pkt->getConstPtr<uint8_t>(), blkSize);
    }
    // We pay for fillLatency here.
    blk->whenReady = clockEdge() + fillLatency * clockPeriod() +
        pkt->payloadDelay;

    return blk;
}


/////////////////////////////////////////////////////
//
// Snoop path: requests coming in from the memory side
//
/////////////////////////////////////////////////////

void
Cache::doTimingSupplyResponse(PacketPtr req_pkt, const uint8_t *blk_data,
                              bool already_copied, bool pending_inval)
{
    // sanity check
    assert(req_pkt->isRequest());
    assert(req_pkt->needsResponse());

    DPRINTF(Cache, "%s for %s addr %#llx size %d\n", __func__,
            req_pkt->cmdString(), req_pkt->getAddr(), req_pkt->getSize());
    // timing-mode snoop responses require a new packet, unless we
    // already made a copy...
    PacketPtr pkt = req_pkt;
    if (!already_copied)
        // do not clear flags, and allocate space for data if the
        // packet needs it (the only packets that carry data are read
        // responses)
        pkt = new Packet(req_pkt, false, req_pkt->isRead());

    assert(req_pkt->req->isUncacheable() || req_pkt->isInvalidate() ||
           pkt->sharedAsserted());
    pkt->makeTimingResponse();
    if (pkt->isRead()) {
        pkt->setDataFromBlock(blk_data, blkSize);
    }
    if (pkt->cmd == MemCmd::ReadResp && pending_inval) {
        // Assume we defer a response to a read from a far-away cache
        // A, then later defer a ReadExcl from a cache B on the same
        // bus as us.  We'll assert MemInhibit in both cases, but in
        // the latter case MemInhibit will keep the invalidation from
        // reaching cache A.  This special response tells cache A that
        // it gets the block to satisfy its read, but must immediately
        // invalidate it.
        pkt->cmd = MemCmd::ReadRespWithInvalidate;
    }
    // Here we consider forward_time, paying for just forward latency and
    // also charging the delay provided by the xbar.
    // forward_time is used as send_time in next allocateWriteBuffer().
    Tick forward_time = clockEdge(forwardLatency) + pkt->headerDelay;
    // Here we reset the timing of the packet.
    pkt->headerDelay = pkt->payloadDelay = 0;
    DPRINTF(Cache, "%s created response: %s addr %#llx size %d tick: %lu\n",
            __func__, pkt->cmdString(), pkt->getAddr(), pkt->getSize(),
            forward_time);
    memSidePort->schedTimingSnoopResp(pkt, forward_time, true);
}

void
Cache::handleSnoop(PacketPtr pkt, CacheBlk *blk, bool is_timing,
                   bool is_deferred, bool pending_inval)
{
    DPRINTF(Cache, "%s for %s addr %#llx size %d\n", __func__,
            pkt->cmdString(), pkt->getAddr(), pkt->getSize());
    // deferred snoops can only happen in timing mode
    assert(!(is_deferred && !is_timing));
    // pending_inval only makes sense on deferred snoops
    assert(!(pending_inval && !is_deferred));
    assert(pkt->isRequest());

    // the packet may get modified if we or a forwarded snooper
    // responds in atomic mode, so remember a few things about the
    // original packet up front
    bool invalidate = pkt->isInvalidate();
    bool M5_VAR_USED needs_exclusive = pkt->needsExclusive();

    if (forwardSnoops) {
        // first propagate snoop upward to see if anyone above us wants to
        // handle it.  save & restore packet src since it will get
        // rewritten to be relative to cpu-side bus (if any)
        bool alreadyResponded = pkt->memInhibitAsserted();
        if (is_timing) {
            // copy the packet so that we can clear any flags before
            // forwarding it upwards, we also allocate data (passing
            // the pointer along in case of static data), in case
            // there is a snoop hit in upper levels
            Packet snoopPkt(pkt, true, true);
            snoopPkt.setExpressSnoop();
            snoopPkt.pushSenderState(new ForwardResponseRecord());
            // the snoop packet does not need to wait any additional
            // time
            snoopPkt.headerDelay = snoopPkt.payloadDelay = 0;
            cpuSidePort->sendTimingSnoopReq(&snoopPkt);
            if (snoopPkt.memInhibitAsserted()) {
                // cache-to-cache response from some upper cache
                assert(!alreadyResponded);
                pkt->assertMemInhibit();
            } else {
                // no cache (or anyone else for that matter) will
                // respond, so delete the ForwardResponseRecord here
                delete snoopPkt.popSenderState();
            }
            if (snoopPkt.sharedAsserted()) {
                pkt->assertShared();
            }
            // If this request is a prefetch or clean evict and an
            // upper level signals block present, make sure to
            // propagate the block presence to the requester.
            if (snoopPkt.isBlockCached()) {
                pkt->setBlockCached();
            }
        } else {
            cpuSidePort->sendAtomicSnoop(pkt);
            if (!alreadyResponded && pkt->memInhibitAsserted()) {
                // cache-to-cache response from some upper cache:
                // forward response to original requester
                assert(pkt->isResponse());
            }
        }
    }

    if (!blk || !blk->isValid()) {
        DPRINTF(Cache, "%s snoop miss for %s addr %#llx size %d\n",
                __func__, pkt->cmdString(), pkt->getAddr(), pkt->getSize());
        return;
    } else {
       DPRINTF(Cache, "%s snoop hit for %s for addr %#llx size %d, "
               "old state is %s\n", __func__, pkt->cmdString(),
               pkt->getAddr(), pkt->getSize(), blk->print());
    }

    // we may end up modifying both the block state and the packet (if
    // we respond in atomic mode), so just figure out what to do now
    // and then do it later.  If we find dirty data while snooping for a
    // WriteInvalidate, we don't care, since no merging needs to take place.
    // We need the eviction to happen as normal, but the data needn't be
    // sent anywhere. nor should the writeback be inhibited at the memory
    // controller for any reason.
    bool respond = blk->isDirty() && pkt->needsResponse()
                                  && !pkt->isWriteInvalidate();
    bool have_exclusive = blk->isWritable();

    // Invalidate any prefetch's from below that would strip write permissions
    // MemCmd::HardPFReq is only observed by upstream caches.  After missing
    // above and in it's own cache, a new MemCmd::ReadReq is created that
    // downstream caches observe.
    if (pkt->cmd == MemCmd::HardPFReq) {
        DPRINTF(Cache, "Squashing prefetch from lower cache %#x\n",
                pkt->getAddr());
        pkt->setBlockCached();
        return;
    }

    if (!pkt->req->isUncacheable() && pkt->isRead() && !invalidate) {
        assert(!needs_exclusive);
        pkt->assertShared();
        int bits_to_clear = BlkWritable;
        const bool haveOwnershipState = true; // for now
        if (!haveOwnershipState) {
            // if we don't support pure ownership (dirty && !writable),
            // have to clear dirty bit here, assume memory snarfs data
            // on cache-to-cache xfer
            bits_to_clear |= BlkDirty;
        }
        blk->status &= ~bits_to_clear;
    }

    if (respond) {
        // prevent anyone else from responding, cache as well as
        // memory, and also prevent any memory from even seeing the
        // request (with current inhibited semantics), note that this
        // applies both to reads and writes and that for writes it
        // works thanks to the fact that we still have dirty data and
        // will write it back at a later point
        pkt->assertMemInhibit();
        if (have_exclusive) {
            // in the case of an uncacheable request there is no need
            // to set the exclusive flag, but since the recipient does
            // not care there is no harm in doing so
            pkt->setSupplyExclusive();
        }
        if (is_timing) {
            doTimingSupplyResponse(pkt, blk->data, is_deferred, pending_inval);
        } else {
            pkt->makeAtomicResponse();
            pkt->setDataFromBlock(blk->data, blkSize);
        }
    }

    if (!respond && is_timing && is_deferred) {
        // if it's a deferred timing snoop then we've made a copy of
        // both the request and the packet, and so if we're not using
        // those copies to respond and delete them here
        DPRINTF(Cache, "Deleting pkt %p and request %p for cmd %s addr: %p\n",
                pkt, pkt->req, pkt->cmdString(), pkt->getAddr());

        // the packets needs a response (just not from us), so we also
        // need to delete the request and not rely on the packet
        // destructor
        assert(pkt->needsResponse());
        delete pkt->req;
        delete pkt;
    }

    // Do this last in case it deallocates block data or something
    // like that
    if (invalidate) {
        if (blk != tempBlock)
            tags->invalidate(blk);
        blk->invalidate();
    }

    DPRINTF(Cache, "new state is %s\n", blk->print());
}


void
Cache::recvTimingSnoopReq(PacketPtr pkt)
{
    DPRINTF(Cache, "%s for %s addr %#llx size %d\n", __func__,
            pkt->cmdString(), pkt->getAddr(), pkt->getSize());

    // Snoops shouldn't happen when bypassing caches
    assert(!system->bypassCaches());

    // no need to snoop writebacks or requests that are not in range
    if (pkt->cmd == MemCmd::Writeback || !inRange(pkt->getAddr())) {
        return;
    }

    bool is_secure = pkt->isSecure();
    CacheBlk *blk = tags->findBlock(pkt->getAddr(), is_secure);

    Addr blk_addr = blockAlign(pkt->getAddr());
    MSHR *mshr = mshrQueue.findMatch(blk_addr, is_secure);

    // Squash any prefetch requests from below on MSHR hits
    if (mshr && pkt->cmd == MemCmd::HardPFReq) {
        DPRINTF(Cache, "Setting block present to squash prefetch from"
                "lower cache on mshr hit %#x\n",
                pkt->getAddr());
        pkt->setBlockCached();
        return;
    }

    // Let the MSHR itself track the snoop and decide whether we want
    // to go ahead and do the regular cache snoop
    if (mshr && mshr->handleSnoop(pkt, order++)) {
        DPRINTF(Cache, "Deferring snoop on in-service MSHR to blk %#llx (%s)."
                "mshrs: %s\n", blk_addr, is_secure ? "s" : "ns",
                mshr->print());

        if (mshr->getNumTargets() > numTarget)
            warn("allocating bonus target for snoop"); //handle later
        return;
    }

    //We also need to check the writeback buffers and handle those
    std::vector<MSHR *> writebacks;
    if (writeBuffer.findMatches(blk_addr, is_secure, writebacks)) {
        DPRINTF(Cache, "Snoop hit in writeback to addr %#llx (%s)\n",
                pkt->getAddr(), is_secure ? "s" : "ns");

        // Look through writebacks for any cachable writes.
        // We should only ever find a single match
        assert(writebacks.size() == 1);
        MSHR *wb_entry = writebacks[0];
        assert(!wb_entry->isUncacheable());
        assert(wb_entry->getNumTargets() == 1);
        PacketPtr wb_pkt = wb_entry->getTarget()->pkt;
        assert(wb_pkt->cmd == MemCmd::Writeback);

        assert(!pkt->memInhibitAsserted());
        pkt->assertMemInhibit();
        if (!pkt->needsExclusive()) {
            pkt->assertShared();
            // the writeback is no longer the exclusive copy in the system
            wb_pkt->clearSupplyExclusive();
        } else {
            // if we're not asserting the shared line, we need to
            // invalidate our copy.  we'll do that below as long as
            // the packet's invalidate flag is set...
            assert(pkt->isInvalidate());
        }
        doTimingSupplyResponse(pkt, wb_pkt->getConstPtr<uint8_t>(),
                               false, false);

        if (pkt->isInvalidate()) {
            // Invalidation trumps our writeback... discard here
            markInService(wb_entry, false);
            delete wb_pkt;
        }
    }

    // If this was a shared writeback, there may still be
    // other shared copies above that require invalidation.
    // We could be more selective and return here if the
    // request is non-exclusive or if the writeback is
    // exclusive.
    handleSnoop(pkt, blk, true, false, false);
}

bool
Cache::CpuSidePort::recvTimingSnoopResp(PacketPtr pkt)
{
    // Express snoop responses from master to slave, e.g., from L1 to L2
    cache->recvTimingSnoopResp(pkt);
    return true;
}

Tick
Cache::recvAtomicSnoop(PacketPtr pkt)
{
    // Snoops shouldn't happen when bypassing caches
    assert(!system->bypassCaches());

    // no need to snoop writebacks or requests that are not in range
    if (pkt->cmd == MemCmd::Writeback || !inRange(pkt->getAddr())) {
        return 0;
    }

    CacheBlk *blk = tags->findBlock(pkt->getAddr(), pkt->isSecure());
    handleSnoop(pkt, blk, false, false, false);
    // We consider forwardLatency here because a snoop occurs in atomic mode
    return forwardLatency * clockPeriod();
}


MSHR *
Cache::getNextMSHR()
{
    // Check both MSHR queue and write buffer for potential requests,
    // note that null does not mean there is no request, it could
    // simply be that it is not ready
    MSHR *miss_mshr  = mshrQueue.getNextMSHR();
    MSHR *write_mshr = writeBuffer.getNextMSHR();

    // If we got a write buffer request ready, first priority is a
    // full write buffer, otherwhise we favour the miss requests
    if (write_mshr &&
        ((writeBuffer.isFull() && writeBuffer.inServiceEntries == 0) ||
         !miss_mshr)) {
        // need to search MSHR queue for conflicting earlier miss.
        MSHR *conflict_mshr =
            mshrQueue.findPending(write_mshr->blkAddr,
                                  write_mshr->isSecure);

        if (conflict_mshr && conflict_mshr->order < write_mshr->order) {
            // Service misses in order until conflict is cleared.
            return conflict_mshr;

            // @todo Note that we ignore the ready time of the conflict here
        }

        // No conflicts; issue write
        return write_mshr;
    } else if (miss_mshr) {
        // need to check for conflicting earlier writeback
        MSHR *conflict_mshr =
            writeBuffer.findPending(miss_mshr->blkAddr,
                                    miss_mshr->isSecure);
        if (conflict_mshr) {
            // not sure why we don't check order here... it was in the
            // original code but commented out.

            // The only way this happens is if we are
            // doing a write and we didn't have permissions
            // then subsequently saw a writeback (owned got evicted)
            // We need to make sure to perform the writeback first
            // To preserve the dirty data, then we can issue the write

            // should we return write_mshr here instead?  I.e. do we
            // have to flush writes in order?  I don't think so... not
            // for Alpha anyway.  Maybe for x86?
            return conflict_mshr;

            // @todo Note that we ignore the ready time of the conflict here
        }

        // No conflicts; issue read
        return miss_mshr;
    }

    // fall through... no pending requests.  Try a prefetch.
    assert(!miss_mshr && !write_mshr);
    if (prefetcher && mshrQueue.canPrefetch()) {
        // If we have a miss queue slot, we can try a prefetch
        PacketPtr pkt = prefetcher->getPacket();
        if (pkt) {
            Addr pf_addr = blockAlign(pkt->getAddr());
            if (!tags->findBlock(pf_addr, pkt->isSecure()) &&
                !mshrQueue.findMatch(pf_addr, pkt->isSecure()) &&
                !writeBuffer.findMatch(pf_addr, pkt->isSecure())) {
                // Update statistic on number of prefetches issued
                // (hwpf_mshr_misses)
                assert(pkt->req->masterId() < system->maxMasters());
                mshr_misses[pkt->cmdToIndex()][pkt->req->masterId()]++;
                // Don't request bus, since we already have it
                return allocateMissBuffer(pkt, curTick(), false);
            } else {
                // free the request and packet
                delete pkt->req;
                delete pkt;
            }
        }
    }

    return NULL;
}


PacketPtr
Cache::getTimingPacket()
{
    MSHR *mshr = getNextMSHR();

    if (mshr == NULL) {
        return NULL;
    }

    // use request from 1st target
    PacketPtr tgt_pkt = mshr->getTarget()->pkt;
    PacketPtr pkt = NULL;

    DPRINTF(CachePort, "%s %s for addr %#llx size %d\n", __func__,
            tgt_pkt->cmdString(), tgt_pkt->getAddr(), tgt_pkt->getSize());

    if (mshr->isForwardNoResponse()) {
        // no response expected, just forward packet as it is
        assert(tags->findBlock(mshr->blkAddr, mshr->isSecure) == NULL);
        pkt = tgt_pkt;
    } else {
        CacheBlk *blk = tags->findBlock(mshr->blkAddr, mshr->isSecure);

        if (tgt_pkt->cmd == MemCmd::HardPFReq && forwardSnoops) {
            // We need to check the caches above us to verify that
            // they don't have a copy of this block in the dirty state
            // at the moment. Without this check we could get a stale
            // copy from memory that might get used in place of the
            // dirty one.
            Packet snoop_pkt(tgt_pkt, true, false);
            snoop_pkt.setExpressSnoop();
            snoop_pkt.senderState = mshr;
            cpuSidePort->sendTimingSnoopReq(&snoop_pkt);

            // Check to see if the prefetch was squashed by an upper cache (to
            // prevent us from grabbing the line) or if a Check to see if a
            // writeback arrived between the time the prefetch was placed in
            // the MSHRs and when it was selected to be sent or if the
            // prefetch was squashed by an upper cache.

            // It is important to check msmInhibitAsserted before
            // prefetchSquashed. If another cache has asserted MEM_INGIBIT, it
            // will be sending a response which will arrive at the MSHR
            // allocated ofr this request. Checking the prefetchSquash first
            // may result in the MSHR being prematurely deallocated.

            if (snoop_pkt.memInhibitAsserted()) {
                // If we are getting a non-shared response it is dirty
                bool pending_dirty_resp = !snoop_pkt.sharedAsserted();
                markInService(mshr, pending_dirty_resp);
                DPRINTF(Cache, "Upward snoop of prefetch for addr"
                        " %#x (%s) hit\n",
                        tgt_pkt->getAddr(), tgt_pkt->isSecure()? "s": "ns");
                return NULL;
            }

            if (snoop_pkt.isBlockCached() || blk != NULL) {
                DPRINTF(Cache, "Block present, prefetch squashed by cache.  "
                               "Deallocating mshr target %#x.\n",
                        mshr->blkAddr);

                // Deallocate the mshr target
                if (mshr->queue->forceDeallocateTarget(mshr)) {
                    // Clear block if this deallocation resulted freed an
                    // mshr when all had previously been utilized
                    clearBlocked((BlockedCause)(mshr->queue->index));
                }
                return NULL;
            }

        }

        pkt = getBusPacket(tgt_pkt, blk, mshr->needsExclusive());

        mshr->isForward = (pkt == NULL);

        if (mshr->isForward) {
            // not a cache block request, but a response is expected
            // make copy of current packet to forward, keep current
            // copy for response handling
            pkt = new Packet(tgt_pkt, false, true);
            if (pkt->isWrite()) {
                pkt->setData(tgt_pkt->getConstPtr<uint8_t>());
            }
        }
    }

    assert(pkt != NULL);
    pkt->senderState = mshr;
    return pkt;
}


Tick
Cache::nextMSHRReadyTime() const
{
    Tick nextReady = std::min(mshrQueue.nextMSHRReadyTime(),
                              writeBuffer.nextMSHRReadyTime());

    // Don't signal prefetch ready time if no MSHRs available
    // Will signal once enoguh MSHRs are deallocated
    if (prefetcher && mshrQueue.canPrefetch()) {
        nextReady = std::min(nextReady,
                             prefetcher->nextPrefetchReadyTime());
    }

    return nextReady;
}

void
Cache::serialize(std::ostream &os)
{
    bool dirty(isDirty());

    if (dirty) {
        warn("*** The cache still contains dirty data. ***\n");
        warn("    Make sure to drain the system using the correct flags.\n");
        warn("    This checkpoint will not restore correctly and dirty data in "
             "the cache will be lost!\n");
    }

    // Since we don't checkpoint the data in the cache, any dirty data
    // will be lost when restoring from a checkpoint of a system that
    // wasn't drained properly. Flag the checkpoint as invalid if the
    // cache contains dirty data.
    bool bad_checkpoint(dirty);
    SERIALIZE_SCALAR(bad_checkpoint);
}

void
Cache::unserialize(Checkpoint *cp, const std::string &section)
{
    bool bad_checkpoint;
    UNSERIALIZE_SCALAR(bad_checkpoint);
    if (bad_checkpoint) {
        fatal("Restoring from checkpoints with dirty caches is not supported "
              "in the classic memory system. Please remove any caches or "
              " drain them properly before taking checkpoints.\n");
    }
}

///////////////
//
// CpuSidePort
//
///////////////

AddrRangeList
Cache::CpuSidePort::getAddrRanges() const
{
    return cache->getAddrRanges();
}

bool
Cache::CpuSidePort::recvTimingReq(PacketPtr pkt)
{
    assert(!cache->system->bypassCaches());

    bool success = false;

    // always let inhibited requests through, even if blocked,
    // ultimately we should check if this is an express snoop, but at
    // the moment that flag is only set in the cache itself
    if (pkt->memInhibitAsserted()) {
        // do not change the current retry state
        bool M5_VAR_USED bypass_success = cache->recvTimingReq(pkt);
        assert(bypass_success);
        return true;
    } else if (blocked || mustSendRetry) {
        // either already committed to send a retry, or blocked
        success = false;
    } else {
        // pass it on to the cache, and let the cache decide if we
        // have to retry or not
        success = cache->recvTimingReq(pkt);
    }

    // remember if we have to retry
    mustSendRetry = !success;
    return success;
}

Tick
Cache::CpuSidePort::recvAtomic(PacketPtr pkt)
{
    return cache->recvAtomic(pkt);
}

void
Cache::CpuSidePort::recvFunctional(PacketPtr pkt)
{
    // functional request
    cache->functionalAccess(pkt, true);
}

Cache::
CpuSidePort::CpuSidePort(const std::string &_name, Cache *_cache,
                         const std::string &_label)
    : BaseCache::CacheSlavePort(_name, _cache, _label), cache(_cache)
{
}

///////////////
//
// MemSidePort
//
///////////////

bool
Cache::MemSidePort::recvTimingResp(PacketPtr pkt)
{
    cache->recvTimingResp(pkt);
    return true;
}

// Express snooping requests to memside port
void
Cache::MemSidePort::recvTimingSnoopReq(PacketPtr pkt)
{
    // handle snooping requests
    cache->recvTimingSnoopReq(pkt);
}

Tick
Cache::MemSidePort::recvAtomicSnoop(PacketPtr pkt)
{
    return cache->recvAtomicSnoop(pkt);
}

void
Cache::MemSidePort::recvFunctionalSnoop(PacketPtr pkt)
{
    // functional snoop (note that in contrast to atomic we don't have
    // a specific functionalSnoop method, as they have the same
    // behaviour regardless)
    cache->functionalAccess(pkt, false);
}

void
Cache::CacheReqPacketQueue::sendDeferredPacket()
{
    // sanity check
    assert(!waitingOnRetry);

    // there should never be any deferred request packets in the
    // queue, instead we resly on the cache to provide the packets
    // from the MSHR queue or write queue
    assert(deferredPacketReadyTime() == MaxTick);

    // check for request packets (requests & writebacks)
    PacketPtr pkt = cache.getTimingPacket();
    if (pkt == NULL) {
        // can happen if e.g. we attempt a writeback and fail, but
        // before the retry, the writeback is eliminated because
        // we snoop another cache's ReadEx.
    } else {
        MSHR *mshr = dynamic_cast<MSHR*>(pkt->senderState);
        // in most cases getTimingPacket allocates a new packet, and
        // we must delete it unless it is successfully sent
        bool delete_pkt = !mshr->isForwardNoResponse();

        // let our snoop responses go first if there are responses to
        // the same addresses we are about to writeback, note that
        // this creates a dependency between requests and snoop
        // responses, but that should not be a problem since there is
        // a chain already and the key is that the snoop responses can
        // sink unconditionally
        if (snoopRespQueue.hasAddr(pkt->getAddr())) {
            DPRINTF(CachePort, "Waiting for snoop response to be sent\n");
            Tick when = snoopRespQueue.deferredPacketReadyTime();
            schedSendEvent(when);

            if (delete_pkt)
                delete pkt;

            return;
        }


        waitingOnRetry = !masterPort.sendTimingReq(pkt);

        if (waitingOnRetry) {
            DPRINTF(CachePort, "now waiting on a retry\n");
            if (delete_pkt) {
                // we are awaiting a retry, but we
                // delete the packet and will be creating a new packet
                // when we get the opportunity
                delete pkt;
            }
            // note that we have now masked any requestBus and
            // schedSendEvent (we will wait for a retry before
            // doing anything), and this is so even if we do not
            // care about this packet and might override it before
            // it gets retried
        } else {
            // As part of the call to sendTimingReq the packet is
            // forwarded to all neighbouring caches (and any
            // caches above them) as a snoop. The packet is also
            // sent to any potential cache below as the
            // interconnect is not allowed to buffer the
            // packet. Thus at this point we know if any of the
            // neighbouring, or the downstream cache is
            // responding, and if so, if it is with a dirty line
            // or not.
            bool pending_dirty_resp = !pkt->sharedAsserted() &&
                pkt->memInhibitAsserted();

            cache.markInService(mshr, pending_dirty_resp);
        }
    }

    // if we succeeded and are not waiting for a retry, schedule the
    // next send considering when the next MSHR is ready, note that
    // snoop responses have their own packet queue and thus schedule
    // their own events
    if (!waitingOnRetry) {
        schedSendEvent(cache.nextMSHRReadyTime());
    }
}

Cache::
MemSidePort::MemSidePort(const std::string &_name, Cache *_cache,
                         const std::string &_label)
    : BaseCache::CacheMasterPort(_name, _cache, _reqQueue, _snoopRespQueue),
      _reqQueue(*_cache, *this, _snoopRespQueue, _label),
      _snoopRespQueue(*_cache, *this, _label), cache(_cache)
{
}

#endif//__MEM_CACHE_CACHE_IMPL_HH__
