/*BEGIN_LEGAL 
Intel Open Source License 

Copyright (c) 2002-2016 Intel Corporation. All rights reserved.
 
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.  Redistributions
in binary form must reproduce the above copyright notice, this list of
conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.  Neither the name of
the Intel Corporation nor the names of its contributors may be used to
endorse or promote products derived from this software without
specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE INTEL OR
ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
END_LEGAL */

/* ===================================================================== */
/*
  @ORIGINAL_AUTHOR: Elena Demikhovsky
*/

/* ===================================================================== */
/*! @file
 */

#include "pin.H"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <assert.h>
#if defined(TARGET_LINUX) || defined(TARGET_ANDROID)
#include <elf.h>
#endif

using namespace std;

/* ===================================================================== */
/* Commandline Switches */
/* ===================================================================== */

KNOB<string> KnobOutputFile(KNOB_MODE_WRITEONCE, "pintool",
    "o", "jit_tool.out", "specify file name");

KNOB<BOOL> KnobJustInitialNum(KNOB_MODE_WRITEONCE, "pintool",
    "just_init", "0", "just test the initial thread number");

KNOB<BOOL> KnobJustQueryAuxv(KNOB_MODE_WRITEONCE, "pintool",
    "just_auxv", "0", "just test availability of auxv values");

ofstream TraceFile;
/* ===================================================================== */

INT32 Usage()
{
    cerr <<
        "This pin tool tests MT attach in JIT mode.\n"
        "\n";
    cerr << KNOB_BASE::StringKnobSummary();
    cerr << endl;
    return -1;
}

void QueryAuxv(const char* name, ADDRINT value)
{
    bool found = false;
    ADDRINT vdso = PIN_GetAuxVectorValue(value, &found);
    if (found)
    {
        TraceFile << name << " value: " << vdso << endl;
    }
    else
    {
        TraceFile << "Could not find auxv value " << name << endl;
    }
}

UINT32  threadCounter=0;
/*
 * Thread Start callback
 */
PIN_LOCK lock;
VOID ThreadStart(THREADID threadid, CONTEXT *ctxt, INT32 flags, VOID *v)
{
    PIN_GetLock(&lock, PIN_GetTid());
    TraceFile << "Thread counter is updated to " << dec <<  (threadCounter+1) << endl;
    ++threadCounter;
    PIN_ReleaseLock(&lock);
}

/*
 * Return TRUE when We received a notification from each thread
*/

BOOL AllThreadsNotifed(unsigned int numOfThreads)
{
    PIN_GetLock(&lock, PIN_GetTid());
    // Check that we don't have any extra thread
    assert(threadCounter <= numOfThreads);
    if (threadCounter == numOfThreads)
    {
        PIN_ReleaseLock(&lock);
        return TRUE;
    }
    PIN_ReleaseLock(&lock);
    return FALSE;
}

int OneThreadNotified()
{
    return threadCounter > 0;
}

VOID ImageLoad(IMG img, void *v)
{
    RTN rtn = RTN_FindByName(img, "ThreadsReady");
    if (RTN_Valid(rtn))
    {
        RTN_Replace(rtn, AFUNPTR(AllThreadsNotifed));
    }

    rtn = RTN_FindByName(img, "MainThreadReady");
    if (RTN_Valid(rtn))
    {
        RTN_Replace(rtn, AFUNPTR(OneThreadNotified));
    }
}

// This function is called when the application exits
VOID Fini(INT32 code, VOID *v)
{
    // Write to a file since cout and cerr maybe closed by the application
    TraceFile << "Fini was called" << endl;

    TraceFile.close();
}

/* ===================================================================== */

int main(int argc, CHAR *argv[])
{
    PIN_InitSymbols();

    if( PIN_Init(argc,argv) )
    {
        return Usage();
    }

    PIN_InitLock(&lock);

    TraceFile.open(KnobOutputFile.Value().c_str());
    TraceFile << hex;
    TraceFile.setf(ios::showbase);

    if (KnobJustInitialNum) {
        TraceFile << "Initial thread counter: " << PIN_GetInitialThreadCount() << endl;
        TraceFile.close();
        PIN_ExitProcess(0);
    }

    if (KnobJustQueryAuxv) {
        QueryAuxv("AT_ENTRY", AT_ENTRY);
        QueryAuxv("UNDEFINED_ENTRY", 0xFFFFFFF);
        TraceFile.close();
        PIN_ExitProcess(0);
    }

    IMG_AddInstrumentFunction(ImageLoad, 0);
    PIN_AddThreadStartFunction(ThreadStart, 0);
    PIN_AddFiniFunction(Fini, 0);
    PIN_StartProgram();

    return 0;
}

/* ===================================================================== */
/* eof */
/* ===================================================================== */
