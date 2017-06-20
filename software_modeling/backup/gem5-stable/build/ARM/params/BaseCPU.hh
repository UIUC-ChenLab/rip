#ifndef __PARAMS__BaseCPU__
#define __PARAMS__BaseCPU__

class BaseCPU;

#include <cstddef>
#include "params/BaseCPU.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "params/ArmStage2MMU.hh"
#include <cstddef>
#include "params/ArmTLB.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/ArmInterrupts.hh"
#include <vector>
#include "params/ArmISA.hh"
#include <cstddef>
#include "params/ArmStage2MMU.hh"
#include <cstddef>
#include "params/ArmTLB.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include "params/InstTracer.hh"
#include <vector>
#include "params/Process.hh"

#include "params/MemObject.hh"

struct BaseCPUParams
    : public MemObjectParams
{
    BaseCPU * checker;
    int cpu_id;
    bool do_checkpoint_insts;
    bool do_quiesce;
    bool do_statistics_insts;
    ArmISA::Stage2MMU * dstage2_mmu;
    ArmISA::TLB * dtb;
    bool function_trace;
    Tick function_trace_start;
    ArmISA::Interrupts * interrupts;
    std::vector< ArmISA::ISA * > isa;
    ArmISA::Stage2MMU * istage2_mmu;
    ArmISA::TLB * itb;
    Counter max_insts_all_threads;
    Counter max_insts_any_thread;
    Counter max_loads_all_threads;
    Counter max_loads_any_thread;
    unsigned numThreads;
    Tick profile;
    Tick progress_interval;
    std::vector< Counter > simpoint_start_insts;
    unsigned socket_id;
    bool switched_out;
    System * system;
    Trace::InstTracer * tracer;
    std::vector< Process * > workload;
    unsigned int port_icache_port_connection_count;
    unsigned int port_dcache_port_connection_count;
};

#endif // __PARAMS__BaseCPU__
