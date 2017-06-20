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


/*! @file
 *  An example of SMC application. 
 */
#include "smc_util.h"
#include "../Utils/sys_memory.h"
#include <stdio.h>

/*!
 * Exit with the specified error message
 */
static void Abort(string msg)
{
    fprintf (stderr, "%s\n", msg.c_str());
    exit(1);
}


/*!
 * The main procedure of the application.
 */
int main(int argc, char *argv[])
{
    fprintf (stderr, "SMC in the image of the application\n");

    // buffer to move foo/bar routines into and execute
    static char staticBuffer[PI_FUNC::MAX_SIZE];
    // Set read-write-execute protection for the buffer 
    size_t pageSize = GetPageSize();
    char * firstPage = (char *)(((size_t)staticBuffer) & ~(pageSize - 1));
    char * endPage = (char *)(((size_t)staticBuffer + sizeof(staticBuffer) + pageSize - 1) & ~(pageSize - 1));
    if (!MemProtect(firstPage, endPage - firstPage, MEM_READ_WRITE_EXEC)) {Abort("MemProtect failed");}
    int printed = 0;
    for (int i = 0; i < 3; ++i)
    {
        FOO_FUNC fooFunc;
        if (!printed)
        {
            FILE *fp = fopen ("smcapp1.out", "w");
            fprintf (fp, "%p\n", staticBuffer);
            printf ("fooFunc.Start() %p fooFunc.End() %p\n", staticBuffer,
                    (void *)((unsigned char *)(staticBuffer) + fooFunc.Size()));
            fclose(fp);
            printed = 1;
        }
        fooFunc.Copy(staticBuffer).Execute().AssertStatus();

        BAR_FUNC barFunc;
        barFunc.Copy(staticBuffer).Execute().AssertStatus();
    }
    fprintf (stderr, "Dynamic code generation\n");
    void * dynamicBuffer;
    dynamicBuffer = MemAlloc(PI_FUNC::MAX_SIZE, MEM_READ_WRITE_EXEC);
    if (dynamicBuffer == 0) {Abort("MemAlloc failed");}

    {
        FOO_FUNC fooFunc;
        fooFunc.Copy(dynamicBuffer);
        if (!MemProtect(dynamicBuffer, PI_FUNC::MAX_SIZE, MEM_READ_EXEC)) {Abort("MemProtect failed");}
        for (int i = 0; i < 6; ++i)
        {
            fooFunc.Execute().AssertStatus();
        }
    }

    if (!MemProtect(dynamicBuffer, PI_FUNC::MAX_SIZE, MEM_READ_WRITE_EXEC)) {Abort("MemProtect failed");}

    {
        BAR_FUNC barFunc;
        barFunc.Copy(dynamicBuffer);
        if (!MemProtect(dynamicBuffer, PI_FUNC::MAX_SIZE, MEM_READ_EXEC)) {Abort("MemProtect failed");}
        for (int i = 0; i < 6; ++i)
        {
            barFunc.Execute().AssertStatus();
        }
    }
    

    return 0;
}

/* ===================================================================== */
/* eof */
/* ===================================================================== */
