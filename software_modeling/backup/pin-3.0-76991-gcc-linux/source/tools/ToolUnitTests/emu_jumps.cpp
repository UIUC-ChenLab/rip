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
/*
 * Emulate instruction that implicitly touch the stack: 
 *     push, pop, leave.
 *     call and return
 */
#include <stdio.h>
#include <iostream>
#include <set>
#include "pin.H"

KNOB<UINT32> KnobDetach(KNOB_MODE_WRITEONCE, "pintool", "d", "-1", "stop tracing at this point");
KNOB<BOOL> KnobLog(KNOB_MODE_WRITEONCE, "pintool", "l", "0", "log all instructions");

static UINT32 scount = 0;
static REG scratchReg;
static std::set<ADDRINT> branchTakenIns;
FILE *out = 0;

VOID PrintIns(void *p, const char *s)
{
    if(!out)
        return;

    fprintf(out, "%6d: %p %s\n", scount, p, s);
    fflush(out);
}

ADDRINT EmuIndJmp(ADDRINT tgtip)
{
    return tgtip;
}

VOID BranchBefore(THREADID tid, ADDRINT pc)
{
    if (0 != tid) return;
    branchTakenIns.insert(pc);
}

VOID BranchTaken(THREADID tid, ADDRINT pc, ADDRINT expected)
{
    if (0 != tid) return;
    ASSERT(pc == expected, "pc = " + hexstr(pc) + "INS_Address() = " + hexstr(expected));
    branchTakenIns.erase(pc);
}

VOID Ins( INS ins, VOID *v )
{
    if (KnobDetach > 0 && scount > KnobDetach)
        return;

    if (KnobLog)
    {
        void *addr = Addrint2VoidStar(INS_Address(ins));
        string disasm = INS_Disassemble(ins);
        PrintIns(addr, disasm.c_str());
    }

    scount++;

    // call and return need also stack manipulation (see emu_stack.cpp)
    // conditional jumps need handling the condition (not supported yet)
    if (INS_IsCall(ins) || INS_IsRet(ins) || INS_Category(ins) == XED_CATEGORY_COND_BR)
        return;

    if (INS_IsIndirectBranchOrCall(ins))
    {
        INS_InsertCall(ins, IPOINT_BEFORE,
            AFUNPTR(EmuIndJmp),
            IARG_BRANCH_TARGET_ADDR,
            IARG_RETURN_REGS, scratchReg, IARG_END);

        INS_InsertIndirectJump(ins, IPOINT_AFTER, scratchReg);
        INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)BranchBefore, IARG_THREAD_ID, IARG_INST_PTR, IARG_END);
        INS_InsertCall(ins, IPOINT_TAKEN_BRANCH, (AFUNPTR)BranchTaken, IARG_THREAD_ID, IARG_INST_PTR, IARG_ADDRINT, INS_Address(ins), IARG_END);

        INS_Delete(ins);
    }
    else if (INS_IsDirectBranchOrCall(ins))
    {
        ADDRINT tgt = INS_DirectBranchOrCallTargetAddress(ins);

        INS_InsertDirectJump(ins, IPOINT_AFTER, tgt);
        INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)BranchBefore, IARG_THREAD_ID, IARG_INST_PTR, IARG_END);
        INS_InsertCall(ins, IPOINT_TAKEN_BRANCH, (AFUNPTR)BranchTaken, IARG_THREAD_ID, IARG_INST_PTR, IARG_ADDRINT, INS_Address(ins), IARG_END);

        INS_Delete(ins);
    }
}

VOID Fini(INT32 code, VOID *v)
{
    if (!branchTakenIns.empty())
    {
        for (std::set<ADDRINT>::iterator it = branchTakenIns.begin(); it != branchTakenIns.end(); it++)
        {
            std::cerr << "Instrumentation for IPOINT_TAKEN_BRANCH for instruction at " << hex << *it << " wasn't executed" << endl;
        }
        ASSERTX(FALSE);
    }
    if (out)
        fclose(out);
}

// argc, argv are the entire command line, including pin -t <toolname> -- ...
int main(int argc, char * argv[])
{
    // Initialize pin
    PIN_Init(argc, argv);

    if (KnobLog)
    {
        out = fopen("emu_jumps.txt", "w");
        if (!out)
            fprintf(stderr, "Can't open log file emu_jumps.txt\n");
    }

    scratchReg = PIN_ClaimToolRegister();
    if (!REG_valid(scratchReg))
    {
        if (out)
            fprintf (out, "Cannot allocate a scratch register.\n");
        fprintf (stderr, "Cannot allocate a scratch register.\n");
        return 1;
    }

    // Register instruction instrumentation callback.
    INS_AddInstrumentFunction(Ins, 0);

    // Register Fini to be called when the application exits
    PIN_AddFiniFunction(Fini, 0);
    
    // Start the program, never returns
    PIN_StartProgram();
    
    return 0;
}

