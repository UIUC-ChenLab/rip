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
# On OS X*, we need to use RIP relative addressing (%rip) to access nonlocal 
# data. This has no effect on Linux.

.data

.extern gprval
.extern agprval
.extern stval
.extern astval
.extern xmmval
.extern axmmval
#ifdef CONTEXT_USING_AVX
.extern ymmval
.extern aymmval
#endif
.extern fpSaveArea

.text

# void ChangeRegsWrapper();
# This wrapper saves and restores the registers used by ChangeRegs.
# This is done in the wrapper since we want ChangeRegs to actually
# change the register values but not to affect the application itself.
# The tool may intercept ChangeRegs and replace it with its own function.
#
# Register usage:
# rax   - used (implicitly) by xsave
# rbx   - used for testing the gpr values
# rcx   - used for holding a pointer to the fp save area (used by fxsave)
# rdx   - used (implicitly) by xsave
# st0   - used (implicitly) for loading a value to the FPU stack
# st2   - used for testing the FPU values
# xmm0  - used for testing the sse values
# ymm1  - used for testing the avx values
#ifndef TARGET_MAC
.type ChangeRegsWrapper,  @function
#endif
.global ChangeRegsWrapper
ChangeRegsWrapper:
    # Save the necessary GPRs
    push    %rax
    push    %rbx
    push    %rcx
    push    %rdx

    # Allign the fpSaveArea
    lea     fpSaveArea(%rip), %rcx
    add     $0x40, %rcx
    and     $0xffffffffffffffc0, %rcx
    # Save the floating-point state
#ifdef CONTEXT_USING_AVX
    push    %rdx
    xor     %rdx, %rdx
    mov     $7, %rax
    xsave   (%rcx)
#else
    fxsave  (%rcx)
#endif

    # Now call ChangeRegs - do the actual test.
    # The tool may intercept this function and modify the register values itself.
    call    ChangeRegs

    # Placeholder for PIN_ExecuteAt
    call    ExecuteAt

    # Save the modified values to memory so the tool can ispect them.
    # This is relevant only when the tool modifies the values.
    call    SaveRegsToMem

    # Restore the floating-point state
#ifdef CONTEXT_USING_AVX
    mov     $7, %rax
    xrstor  (%rcx)
    pop     %rdx
#else
    fxrstor (%rcx)
#endif

    # Restore the GPRs
    pop     %rdx
    pop     %rcx
    pop     %rbx
    pop     %rax
    ret

# void ChangeRegs();
# For register usage see ChangeRegsWrapper above.
#ifndef TARGET_MAC
.type ChangeRegs,  @function
#endif
.global ChangeRegs
ChangeRegs:
    # TEST: load the new value to rbx
    mov     gprval(%rip), %rbx
    # prepare the test value at the top of the FPU stack
    fldt    stval(%rip)
    # TEST: load the new value to st2
    fst     %st(2)
    # TEST: load the new value to xmm0
    movdqu  xmmval(%rip), %xmm0
#ifdef CONTEXT_USING_AVX
    # TEST: load the new value to ymm1
    vmovdqu ymmval(%rip), %ymm1
#endif
    ret

# void ExecuteAt();
#ifndef TARGET_MAC
.type ExecuteAt,  @function
#endif
.global ExecuteAt
ExecuteAt:
    ret

# void SaveRegsToMem();
# Save the necessary registers to memory.
# The tool will then compare the value stored in memory to the ones it expects to find.
# For register usage see ChangeRegsWrapper above.
#ifndef TARGET_MAC
.type SaveRegsToMem,  @function
#endif
.global SaveRegsToMem
SaveRegsToMem:
    # TEST: store the new value of rbx
    mov     %rbx, agprval(%rip)
    # prepare the test value at the top of the FPU stack
    fld     %st(2)
    # TEST: store the new value of st2
    fstpt   astval(%rip)
    # TEST: store the new value of xmm0
    movdqu  %xmm0, axmmval(%rip)
#ifdef CONTEXT_USING_AVX
    # TEST: store the new value of ymm1
    vmovdqu %ymm1, aymmval(%rip)
#endif
    ret
