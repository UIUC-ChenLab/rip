%module(package="m5.internal") param_BaseCPU

%{
#include "sim/sim_object.hh"
#include "params/BaseCPU.hh"
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
#include "cpu/base.hh"
/**
  * This is a workaround for bug in swig. Prior to gcc 4.6.1 the STL
  * headers like vector, string, etc. used to automatically pull in
  * the cstddef header but starting with gcc 4.6.1 they no longer do.
  * This leads to swig generated a file that does not compile so we
  * explicitly include cstddef. Additionally, including version 2.0.4,
  * swig uses ptrdiff_t without the std:: namespace prefix which is
  * required with gcc 4.6.1. We explicitly provide access to it.
  */
#include <cstddef>
using std::ptrdiff_t;
%}

%import "python/m5/internal/param_BaseCPU.i"
%import "stdint.i"
%import "base/types.hh"
%import "python/m5/internal/param_ArmStage2MMU.i"
%import "python/m5/internal/param_ArmTLB.i"
%import "stdint.i"
%import "base/types.hh"
%import "python/m5/internal/param_ArmInterrupts.i"
%import "ArmISA_vector.i"
%import "python/m5/internal/param_ArmStage2MMU.i"
%import "python/m5/internal/param_ArmTLB.i"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"
%import "stdint.i"
%import "base/types.hh"
%import "Counter_vector.i"
%import "stdint.i"
%import "base/types.hh"
%import "python/m5/internal/param_System.i"
%import "python/m5/internal/param_InstTracer.i"
%import "Process_vector.i"

%import "python/m5/internal/param_MemObject.i"


// stop swig from creating/wrapping default ctor/dtor
%nodefault BaseCPU;
class BaseCPU
    : public MemObject
{
  public:
    void switchOut();
    void takeOverFrom(BaseCPU *cpu);
    bool switchedOut();
    void flushTLBs();
    Counter totalInsts();
    void scheduleInstStop(ThreadID tid, Counter insts, const char *cause);
    void scheduleLoadStop(ThreadID tid, Counter loads, const char *cause);
};

%include "params/BaseCPU.hh"
