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
#include <cstring>
#include <cstdio>

#ifdef TARGET_WINDOWS
# define ASMNAME(name)
# define ALIGN64 __declspec(align(64))
#else
# define ASMNAME(name) asm(name)
# define ALIGN64 __attribute__ ((aligned (64)))
#endif

#ifdef TARGET_IA32
typedef long ADDRINT;
#define ADDRINT_FORMAT "%lx"
#else
typedef long long ADDRINT;
#define ADDRINT_FORMAT "%llx"
#endif

/////////////////////
// EXTERNAL FUNCTIONS
/////////////////////

extern "C" void DoXsave() ASMNAME("DoXsave");
extern "C" void DoXsaveOpt() ASMNAME("DoXsaveOpt");
extern "C" void DoXrstor() ASMNAME("DoXrstor");


/////////////////////
// GLOBAL VARIABLES
/////////////////////

extern "C"
{
// the current size is large enough for avx512
unsigned char ALIGN64 xsaveArea[2688] ASMNAME("xsaveArea");
ADDRINT flags ASMNAME("flags");
}

ADDRINT checkedFlags [10] = {
                            0x00, /* none */
                            0x03, /* only legacy */
                            0x04, /* only avx    */
                            0x07, /* combo1 legacy + AVX */
                            0x18, /* only BND    */
                            0x1c, /* combo2 BND + AVX */
                            0xc4, /* combo3 some AVX512 + AVX */
                            0xd5, /* combo4 some AVX512 + some BND + AVX + some legacy */
                            0xe0, /* only AVX512 */
                            0xff  /* all  */
                          };

int main(int argc, const char* argv[])
{
    memset(xsaveArea, 0, sizeof(xsaveArea));

    for (int i=0; i<4; i++) {
      flags = checkedFlags[i];

      DoXsave(); // get the register value before the change
      printf("XSAVE on 0x" ADDRINT_FORMAT "\n", (ADDRINT)xsaveArea);

      DoXsaveOpt(); // get the register value before the change
      printf("XSAVEOPT on 0x" ADDRINT_FORMAT "\n", (ADDRINT)xsaveArea);

      DoXrstor(); // restor the register value
      printf("XRSTOR on 0x" ADDRINT_FORMAT "\n", (ADDRINT)xsaveArea);
   }


   return 0;
}
