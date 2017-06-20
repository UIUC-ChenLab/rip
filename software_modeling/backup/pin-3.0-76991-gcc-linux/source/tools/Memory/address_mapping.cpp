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
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <assert.h>
#include "pin.H"

// This PIN tool shall check PIN's memory address confinement.
//

/* ===================================================================== */
/* Commandline Switches */
/* ===================================================================== */

//Output file where to write everything
KNOB<string> KnobOutputFile(KNOB_MODE_WRITEONCE,    "pintool",
    "o", "address_mapping.out", "specify output file name");

//If true, this tool will generate an out of memory condition for PIN's allocator
KNOB<BOOL> KnobGenerateOOM(KNOB_MODE_WRITEONCE,    "pintool",
    "m", "0", "generate an out of memory condition");

//When specified, this tool will check that dynamic memory allocations return
//addresses within that region
KNOB<ADDRESS_RANGE> KnobMemoryBoundary(KNOB_MODE_WRITEONCE,    "pintool",
    "b", "0:0", "The memory boundary to check for dynamic allocation");

//When specified, this tool will check that all allocated code cache blocks
//have memory addresses within that region
KNOB<ADDRESS_RANGE> KnobCCBoundary(KNOB_MODE_WRITEONCE,    "pintool",
    "c", "0:0", "The memory boundary to check for code cache");

//Before PIN initialized, it is using a small pre-allocated memory pool for all dynamic
//memory allocation. This pre-allocated pool is outside the specified region for memory
//allocation.
//We need to make sure that we won't check that the pointers returned from malloc()
//which were allocated by the initial allocator.
//To do so, we allocate enough memory at the begining of the check in order to have the
//initial pool exhausted.
//In order to allocate just enough memory to exhaust the initial allocator
//We need to have some sizes defined for PIN's allocator
#ifdef TARGET_WINDOWS
//Size of PIN's malloc pool for small memory allocations
static const int MALLOC_POOL_SIZE = 0x10000;
#else
//Size of PIN's malloc pool for small memory allocations
static const int MALLOC_POOL_SIZE = 0x1000;

//The total size of PIN's initial allocator, the one that allocates memory before PIN initializes
# ifdef TARGET_MAC
static const int BSS_ALLOCATOR_SIZE = 0x1300000;
# elif TARGET_ANDROID
static const int BSS_ALLOCATOR_SIZE = 0xf00000;
# else
static const int BSS_ALLOCATOR_SIZE = 0xc0000;
# endif
#endif //TARGET_WINDOWS

/* ===================================================================== */
/* Globals */
/* ===================================================================== */

//Output file
FILE * out;

void* AllocateAndCheckAddressRange(size_t sz, int retries = 0)
{
    void* p = NULL;
    //For small allocations, we might allocate memory in a pool which was allocated prior to PIN's
    //initialization. So, try to allocate memory until we exhaust the old pool and get a new pool
    //in the desired memory region
    if (0 == retries)
    {
        //If retires==0, it means that we need to figure out how many retries to
        //perform in order to skip the pages allocated before PIN was initialized
        retries = 1;
        if (sz <= MALLOC_POOL_SIZE / 2)
        {
            retries = (MALLOC_POOL_SIZE / sz);
        }
    }
    while (retries-- > 0)
    {
        p = malloc(sz);
        if (NULL == p)
        {
            fprintf(out, "Failed to allocate dynamic memory with size %d.\n", (int)sz);
            fclose(out);
            PIN_ExitProcess(1);
        }
        fprintf(out, "%d) Allocated buffer %p, with size %d\n", retries, p, (int)sz);
        ADDRINT addrint = (ADDRINT)p;
        if (addrint >= KnobMemoryBoundary.Value()._low && addrint <= KnobMemoryBoundary.Value()._high)
        {
            return p;
        }
    }
    fprintf(out, "Allocated memory of size %d in address %p which is out of range.\n", (int)sz, p);
    fclose(out);
    PIN_ExitProcess(2);
}

VOID OutOfMemory(size_t sz, VOID* arg)
{
    fprintf(out, "Failed to allocate dynamic memory: Out of memory!\n");
    fclose(out);
    PIN_ExitProcess(3);
}

//This function will check that memory the is dynamically allocated is allocated in
//the right addresses
VOID Fini(INT32 code, VOID *v)
{
    vector<void*> smallMallocs;
#ifndef TARGET_WINDOWS
    //Skip memory allocated by the BSS allocator
    void* initialPtr = AllocateAndCheckAddressRange(MALLOC_POOL_SIZE, BSS_ALLOCATOR_SIZE/MALLOC_POOL_SIZE);
    free(initialPtr);
#endif
// Allocation for big memory region: This malloc should allocate memory directly from the OS
    void* bigMalloc = AllocateAndCheckAddressRange(0x100000); 
    for (int i = 4; i < 0x10000; i *= 2)
    {
// Allocation for small memory region: This malloc should allocate memory from a memory pool
        void* smallOne = AllocateAndCheckAddressRange(i);
        smallMallocs.push_back(smallOne);
    }
    for (int i = 0; i < 0x1000; i++)
    {
        void* p = AllocateAndCheckAddressRange(0x10000);
        if (!KnobGenerateOOM.Value())
        {
        	//In order to generate an out of memory - just don't free the allocated pointers
            free(p);
        }
    }
    free(bigMalloc);
    for (vector<void*>::iterator it = smallMallocs.begin(); it != smallMallocs.end(); it++)
    {
        free(*it);
    }
    fprintf(out, "Test successful.\n");
    fclose(out);
}

//Check that the instructions inside the code cache blocks are in the allowed memory region
VOID Trace(TRACE trace, VOID *v)
{
    for (BBL bbl = TRACE_BblHead(trace); BBL_Valid(bbl); bbl = BBL_Next(bbl))
    {
        for (INS ins = BBL_InsHead(bbl); INS_Valid(ins); ins = INS_Next(ins))
        {
            ADDRINT cache_pc = INS_CodeCacheAddress(ins);

            if ( cache_pc != 0x0 )
            {
                if (cache_pc < KnobCCBoundary.Value()._low || cache_pc > KnobCCBoundary.Value()._high)
                {
                    fprintf(out, "Instruction '%s' is at bad address on code cache (%lx)\n", INS_Disassemble(ins).c_str(), (long)cache_pc);
                    fclose(out);
                    PIN_ExitProcess(3);
                }
            }
        }
    }
}

int main(int argc, char * argv[])
{
    PIN_InitSymbols();
    PIN_Init(argc, argv);

    out = fopen(KnobOutputFile.Value().c_str(), "w");
    if (KnobMemoryBoundary.Value()._high == 0)
    {
        fprintf(out, "Must specified the knob -%s to this tool.\n", KnobMemoryBoundary.Name().c_str());
        PIN_ExitProcess(5);
    }

    if (KnobCCBoundary.Value().Valid())
    {
        fprintf(out, "Will check that code cache is in %lx:%lx.\n",
                (unsigned long)KnobCCBoundary.Value()._low,
                (unsigned long)KnobCCBoundary.Value()._high);
        // Register a routine that gets called when a trace is
        //  inserted into the codecache
        CODECACHE_AddTraceInsertedFunction(Trace, 0);
    }

    PIN_AddOutOfMemoryFunction(OutOfMemory, NULL);
    PIN_AddFiniFunction(Fini, 0);
    // Never returns
    PIN_StartProgram();

    return 0;
}
