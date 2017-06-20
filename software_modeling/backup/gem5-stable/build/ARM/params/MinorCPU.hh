#ifndef __PARAMS__MinorCPU__
#define __PARAMS__MinorCPU__

class MinorCPU;

#include <cstddef>
#include "params/BranchPredictor.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "params/MinorFUPool.hh"
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
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
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
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BaseCPU.hh"

struct MinorCPUParams
    : public BaseCPUParams
{
    MinorCPU * create();
    BPredUnit * branchPred;
    bool decodeCycleInput;
    unsigned decodeInputBufferSize;
    unsigned decodeInputWidth;
    Cycles decodeToExecuteForwardDelay;
    bool enableIdling;
    bool executeAllowEarlyMemoryIssue;
    Cycles executeBranchDelay;
    unsigned executeCommitLimit;
    bool executeCycleInput;
    MinorFUPool * executeFuncUnits;
    unsigned executeInputBufferSize;
    unsigned executeInputWidth;
    unsigned executeIssueLimit;
    unsigned executeLSQMaxStoreBufferStoresPerCycle;
    unsigned executeLSQRequestsQueueSize;
    unsigned executeLSQStoreBufferSize;
    unsigned executeLSQTransfersQueueSize;
    unsigned executeMaxAccessesInMemory;
    unsigned executeMemoryCommitLimit;
    unsigned executeMemoryIssueLimit;
    unsigned executeMemoryWidth;
    bool executeSetTraceTimeOnCommit;
    bool executeSetTraceTimeOnIssue;
    unsigned fetch1FetchLimit;
    unsigned fetch1LineSnapWidth;
    unsigned fetch1LineWidth;
    Cycles fetch1ToFetch2BackwardDelay;
    Cycles fetch1ToFetch2ForwardDelay;
    bool fetch2CycleInput;
    unsigned fetch2InputBufferSize;
    Cycles fetch2ToDecodeForwardDelay;
};

#endif // __PARAMS__MinorCPU__
