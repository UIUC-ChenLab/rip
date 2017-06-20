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
#include <string.h>
#ifndef TARGET_MAC
#include <malloc.h>
#endif
#if defined(TARGET_LINUX) || defined(PIN_CRT)
#include <unistd.h>
#endif
#include "pin.H"

#if defined(PIN_CRT)
#    define HAVE_POSIX_MEMALIGN
#    define HAVE_MEMALIGN
#    define HAVE_VALLOC
#elif defined(TARGET_WINDOWS)
#    define HAVE_ALIGNED_MALLOC
#elif defined(TARGET_MAC)
#    define HAVE_POSIX_MEMALIGN
#    define HAVE_VALLOC
#elif defined(TARGET_ANDROID)
#    define HAVE_MEMALIGN
#elif defined(TARGET_LINUX)
#    define HAVE_POSIX_MEMALIGN
#    define HAVE_MEMALIGN
#    define HAVE_VALLOC
#endif


/* ===================================================================== */
/* Commandline Switches */
/* ===================================================================== */

KNOB<string> KnobOutputFile(KNOB_MODE_WRITEONCE,    "pintool",
    "o", "memalign.out", "specify output file name");


/* ===================================================================== */
/* Globals */
/* ===================================================================== */

FILE * out;

#define NUMBER_OF_ALIGNMENTS_TO_CHECK 12
#define SIZE_TO_ALLOCATE 117

VOID AlignCheck(const char* msg, VOID* p, int alignment, int size)
{
    if (p == NULL)
    {
        fprintf(out, "Failed to allocate aligned memory from %s. Alignment=%d, size=%d.\n", msg, alignment, size);
        abort();
    }
    ADDRINT mask = alignment - 1;
    ADDRINT addr = (ADDRINT)p;
    if ((addr & mask) != 0)
    {
        fprintf(out, "Memory allocated from %s is not alligned. Returned memory %p, Alignment=%d, size=%d.\n", msg, p, alignment, size);
    }
    memset(p, 0x12345678, size);
}

VOID Fini(INT32 code, VOID *v)
{
    int alignment = sizeof(VOID*);
    for (int i = 1; i < NUMBER_OF_ALIGNMENTS_TO_CHECK; i++)
    {
        void *p = NULL;
#ifdef HAVE_ALIGNED_MALLOC
        fprintf(out, "Calling _aligned_malloc\n");
        p = _aligned_malloc(SIZE_TO_ALLOCATE, alignment);
        AlignCheck("_aligned_malloc", p , alignment, SIZE_TO_ALLOCATE);
        fprintf(out, "Free _aligned_malloc. p=%p\n", p);
        fflush(out);
        _aligned_free(p);
#endif // HAVE_ALIGNED_MALLOC
#ifdef HAVE_POSIX_MEMALIGN
        fprintf(out, "Calling posix_memalign. Alignment=%d\n", alignment);
        if (posix_memalign(&p, alignment, SIZE_TO_ALLOCATE))
            p = NULL;
        AlignCheck("posix_memalign", p, alignment, SIZE_TO_ALLOCATE);
        fprintf(out, "Free posix_memalign. p=%p\n", p);
        fflush(out);
        free(p);
#endif // HAVE_POSIX_MEMALIGN
#ifdef HAVE_MEMALIGN
        fprintf(out, "Calling memalign. Alignment=%d\n", alignment);
        p = memalign(alignment, SIZE_TO_ALLOCATE);
        AlignCheck("memalign", p, alignment, SIZE_TO_ALLOCATE);
        fprintf(out, "Free memalign. p=%p\n", p);
        fflush(out);
        free(p);
#endif // HAVE_MEMALIGN

        alignment *= 2;
    }
#ifdef HAVE_VALLOC
    fprintf(out, "Calling valloc\n");
    void* p = valloc(SIZE_TO_ALLOCATE);
    AlignCheck("valloc", p, 
# if defined(TARGET_MAC) || defined(PIN_CRT)
        getpagesize(),
# else
        sysconf(_SC_PAGESIZE),
# endif
        SIZE_TO_ALLOCATE);
    fprintf(out, "Free valloc. p=%p\n", p);
    fflush(out);
    free(p);
#endif // HAVE_VALLOC
    fclose(out);
}

int main(int argc, char * argv[])
{
    PIN_Init(argc, argv);

    out = fopen(KnobOutputFile.Value().c_str(), "w");

    PIN_AddFiniFunction(Fini, 0);
    // Never returns
    PIN_StartProgram();

    return 0;
}
