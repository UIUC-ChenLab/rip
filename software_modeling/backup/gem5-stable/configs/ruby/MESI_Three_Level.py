# Copyright (c) 2006-2007 The Regents of The University of Michigan
# Copyright (c) 2009 Advanced Micro Devices, Inc.
# Copyright (c) 2013 Mark D. Hill and David A. Wood
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met: redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer;
# redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution;
# neither the name of the copyright holders nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# Authors: Brad Beckmann
#          Nilay Vaish

import math
import m5
from m5.objects import *
from m5.defines import buildEnv
from Ruby import create_topology
from Ruby import send_evicts

#
# Note: the L1 Cache latency is only used by the sequencer on fast path hits
#
class L0Cache(RubyCache):
    latency = 1

class L1Cache(RubyCache):
    latency = 5

#
# Note: the L2 Cache latency is not currently used
#
class L2Cache(RubyCache):
    latency = 15

def define_options(parser):
    parser.add_option("--num-clusters", type="int", default=1,
            help="number of clusters in a design in which there are shared\
            caches private to clusters")
    return

def create_system(options, full_system, system, dma_ports, ruby_system):

    if buildEnv['PROTOCOL'] != 'MESI_Three_Level':
        fatal("This script requires the MESI_Three_Level protocol to be built.")

    cpu_sequencers = []

    #
    # The ruby network creation expects the list of nodes in the system to be
    # consistent with the NetDest list.  Therefore the l1 controller nodes must be
    # listed before the directory nodes and directory nodes before dma nodes, etc.
    #
    l0_cntrl_nodes = []
    l1_cntrl_nodes = []
    l2_cntrl_nodes = []
    dir_cntrl_nodes = []
    dma_cntrl_nodes = []

    assert (options.num_cpus % options.num_clusters == 0)
    num_cpus_per_cluster = options.num_cpus / options.num_clusters

    assert (options.num_l2caches % options.num_clusters == 0)
    num_l2caches_per_cluster = options.num_l2caches / options.num_clusters

    l2_bits = int(math.log(num_l2caches_per_cluster, 2))
    block_size_bits = int(math.log(options.cacheline_size, 2))
    l2_index_start = block_size_bits + l2_bits

    #
    # Must create the individual controllers before the network to ensure the
    # controller constructors are called before the network constructor
    #
    for i in xrange(options.num_clusters):
        for j in xrange(num_cpus_per_cluster):
            #
            # First create the Ruby objects associated with this cpu
            #
            l0i_cache = L0Cache(size = '4096B', assoc = 1, is_icache = True,
                start_index_bit = block_size_bits, replacement_policy="LRU")

            l0d_cache = L0Cache(size = '4096B', assoc = 1, is_icache = False,
                start_index_bit = block_size_bits, replacement_policy="LRU")

            l0_cntrl = L0Cache_Controller(version = i*num_cpus_per_cluster + j,
                          Icache = l0i_cache, Dcache = l0d_cache,
                          send_evictions = send_evicts(options),
                          clk_domain=system.cpu[i].clk_domain,
                          ruby_system = ruby_system)

            cpu_seq = RubySequencer(version = i, icache = l0i_cache,
                        clk_domain=system.cpu[i].clk_domain,
                        dcache = l0d_cache, ruby_system = ruby_system)

            l0_cntrl.sequencer = cpu_seq

            l1_cache = L1Cache(size = options.l1d_size, assoc = options.l1d_assoc,
                            start_index_bit = block_size_bits, is_icache = False)

            l1_cntrl = L1Cache_Controller(version = i*num_cpus_per_cluster+j,
                          cache = l1_cache, l2_select_num_bits = l2_bits,
                          cluster_id = i, ruby_system = ruby_system)

            exec("ruby_system.l0_cntrl%d = l0_cntrl" % (
                        i*num_cpus_per_cluster+j))
            exec("ruby_system.l1_cntrl%d = l1_cntrl" % (
                        i*num_cpus_per_cluster+j))

            #
            # Add controllers and sequencers to the appropriate lists
            #
            cpu_sequencers.append(cpu_seq)
            l0_cntrl_nodes.append(l0_cntrl)
            l1_cntrl_nodes.append(l1_cntrl)

            # Connect the L0 and L1 controllers
            l0_cntrl.bufferToL1 = l1_cntrl.bufferFromL0
            l0_cntrl.bufferFromL1 = l1_cntrl.bufferToL0

            # Connect the L1 controllers and the network
            l1_cntrl.requestToL2 =  ruby_system.network.slave
            l1_cntrl.responseToL2 =  ruby_system.network.slave
            l1_cntrl.unblockToL2 =  ruby_system.network.slave

            l1_cntrl.requestFromL2 =  ruby_system.network.master
            l1_cntrl.responseFromL2 =  ruby_system.network.master


        for j in xrange(num_l2caches_per_cluster):
            l2_cache = L2Cache(size = options.l2_size,
                               assoc = options.l2_assoc,
                               start_index_bit = l2_index_start)

            l2_cntrl = L2Cache_Controller(
                        version = i * num_l2caches_per_cluster + j,
                        L2cache = l2_cache, cluster_id = i,
                        transitions_per_cycle=options.ports,
                        ruby_system = ruby_system)

            exec("ruby_system.l2_cntrl%d = l2_cntrl" % (
                        i * num_l2caches_per_cluster + j))
            l2_cntrl_nodes.append(l2_cntrl)

            # Connect the L2 controllers and the network
            l2_cntrl.DirRequestFromL2Cache = ruby_system.network.slave
            l2_cntrl.L1RequestFromL2Cache = ruby_system.network.slave
            l2_cntrl.responseFromL2Cache = ruby_system.network.slave

            l2_cntrl.unblockToL2Cache = ruby_system.network.master
            l2_cntrl.L1RequestToL2Cache = ruby_system.network.master
            l2_cntrl.responseToL2Cache = ruby_system.network.master

    phys_mem_size = sum(map(lambda r: r.size(), system.mem_ranges))
    assert(phys_mem_size % options.num_dirs == 0)
    mem_module_size = phys_mem_size / options.num_dirs

    # Run each of the ruby memory controllers at a ratio of the frequency of
    # the ruby system
    # clk_divider value is a fix to pass regression.
    ruby_system.memctrl_clk_domain = DerivedClockDomain(
                                          clk_domain=ruby_system.clk_domain,
                                          clk_divider=3)

    for i in xrange(options.num_dirs):
        #
        # Create the Ruby objects associated with the directory controller
        #
        dir_size = MemorySize('0B')
        dir_size.value = mem_module_size

        dir_cntrl = Directory_Controller(version = i,
                                         directory = RubyDirectoryMemory(
                                             version = i, size = dir_size),
                                         transitions_per_cycle = options.ports,
                                         ruby_system = ruby_system)

        exec("ruby_system.dir_cntrl%d = dir_cntrl" % i)
        dir_cntrl_nodes.append(dir_cntrl)

        # Connect the directory controllers and the network
        dir_cntrl.requestToDir = ruby_system.network.master
        dir_cntrl.responseToDir = ruby_system.network.master
        dir_cntrl.responseFromDir = ruby_system.network.slave

    for i, dma_port in enumerate(dma_ports):
        #
        # Create the Ruby objects associated with the dma controller
        #
        dma_seq = DMASequencer(version = i,
                               ruby_system = ruby_system)

        dma_cntrl = DMA_Controller(version = i,
                                   dma_sequencer = dma_seq,
                                   transitions_per_cycle = options.ports,
                                   ruby_system = ruby_system)

        exec("ruby_system.dma_cntrl%d = dma_cntrl" % i)
        exec("ruby_system.dma_cntrl%d.dma_sequencer.slave = dma_port" % i)
        dma_cntrl_nodes.append(dma_cntrl)

        # Connect the dma controller to the network
        dma_cntrl.responseFromDir = ruby_system.network.master
        dma_cntrl.requestToDir = ruby_system.network.slave

    all_cntrls = l0_cntrl_nodes + \
                 l1_cntrl_nodes + \
                 l2_cntrl_nodes + \
                 dir_cntrl_nodes + \
                 dma_cntrl_nodes

    # Create the io controller and the sequencer
    if full_system:
        io_seq = DMASequencer(version=len(dma_ports), ruby_system=ruby_system)
        ruby_system._io_port = io_seq
        io_controller = DMA_Controller(version = len(dma_ports),
                                       dma_sequencer = io_seq,
                                       ruby_system = ruby_system)
        ruby_system.io_controller = io_controller

        # Connect the dma controller to the network
        io_controller.responseFromDir = ruby_system.network.master
        io_controller.requestToDir = ruby_system.network.slave

        all_cntrls = all_cntrls + [io_controller]

    topology = create_topology(all_cntrls, options)
    return (cpu_sequencers, dir_cntrl_nodes, topology)
