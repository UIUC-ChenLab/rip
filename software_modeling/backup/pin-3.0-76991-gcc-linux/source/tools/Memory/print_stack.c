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
#include <stdio.h>
#include <stdint.h>
#include <sys/mman.h>

#define PAGE_TO_CONSUME 0x500

/*
 * This function will consume (at least) numPagesDoubled of half pages
 * (2KB each) from the stack memory.
 */
void consumeHalfPages(int numPagesDoubled)
{
    int i;
    char buf[2048];
    if (--numPagesDoubled > 0)
        consumeHalfPages(numPagesDoubled);
    for (i = 0; i < sizeof(buf); i++)
        buf[i] = (char)i;

    // Dummy print to prevent opt-out of 'buf'
    printf("%s", buf);
}

int main( int argc, char **argv, char **envp )
{
   intptr_t sp = (intptr_t)&argc;
   size_t pgsize = getpagesize();
   void* end_of_stack = NULL;
   sp &= ~(pgsize-1);

   // Find the end of the stack (the page before the one that mprotect fails on)
   for (end_of_stack = (void*)sp; 0 == mprotect(end_of_stack + pgsize, pgsize,PROT_READ|PROT_WRITE); end_of_stack += pgsize);

   // print part of the stack in PIN's -reserve_memory file format
   printf("%p %p data 0\n", (void*)(sp - PAGE_TO_CONSUME * pgsize), end_of_stack);

   // The call below will consume at least PAGE_TO_CONSUME*4KB memory from the stack
   consumeHalfPages(PAGE_TO_CONSUME * 2);

   return 0;
}
