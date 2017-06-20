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
#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;
using std::flush;
using std::hex;
using std::dec;
#if defined(TARGET_WINDOWS)
#include<windows.h>
#define EXPORT_SYM extern "C" __declspec(dllexport) __declspec(noinline)
#else
#include <sys/mman.h>
#define EXPORT_SYM extern "C"
#endif

const unsigned int arraySize = 1000;
static char theArray[arraySize];

EXPORT_SYM void AppMarker()
{
    cout << "APP: AppMarker executed" << endl << flush;
}

int main()
{
    cout << "APP: Begin test" << endl << flush;
    cout << "APP: calling munmap(" << hex << (void*)theArray << "," << dec << arraySize << ")" << endl << flush;
#if defined(TARGET_WINDOWS)
    if (0 != VirtualFree(theArray, arraySize, MEM_RELEASE))
    {
        cout << "APP: ERROR: munmap of a variable in the BSS (wrongly) succeeded";
        return 1;
    }
#else
    if (0 == munmap(theArray, arraySize))
    {
        cout << "APP: ERROR: munmap of a variable in the BSS (wrongly) succeeded";
        return 1;
    }
#endif
    perror("APP: munmap failed as expected");
    AppMarker();
    cout << "APP: End test" << endl << flush;
    return 0;
}
