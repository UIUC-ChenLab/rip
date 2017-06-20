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

.text

# int DoJkzdTests();
#
# This function calls jkzd twice in a row, first with k2 and followed by k3. We expect the branch to be taken
# only for k2. Pin will jit this function and we want to make sure that it jits correctly:
# 1. Pin uses k1 as its dummy register when generating a jkzd instruction. This test veirifies that Pin uses
#    the designated application register for the actual jkzd encoding, not k1. To check that, k1 always has
#    the opposite value than the tested register (which will cause a failure).
# 2. The ins reuse manager should not use the same ins object for the different registers. To check that, the
#    test registers have opposite values, so if the same ins object is used, the second jkzd instruction will
#    cause the test to fail.
# k1 is either zeroed out or all ones, so it will be the opposite of the mask register being used.
#
# Return value: 0 if both test jkzd instructions were executed as expected. 1 otherwise.
#
# Register usage:
# rax   - return value
# rbx   - used for storing and loading the mask registers
# rsi   - used for control flow
# k1    - dummy register (see details above)
# k2    - used for testing jkzd
# k3    - used for testing jkzd
.global DoJkzdTests
.type DoJkzdTests,  @function
DoJkzdTests:
    # Save the necessary registers and prepare their values for the tests
    push    %rsi
    lea     jkzdtestk2, %rsi
    jmp     PrepareRegs

jkzdtestk2:
    # This branch should be taken
    jkzd    jkzdtestk3, %k2
    jmp     jkzdfinish

jkzdtestk3:
    kmov %k1, %eax
    knot    %k1, %k1
    kmov %k1, %eax
    # This branch should not be taken
    jkzd    jkzdfinish, %k3

jkzdsuccess:
    # All tests completed successfully - set return value to 0 (success)
    mov     $0x0, %rax

jkzdfinish:
    # Restore the original register values
    lea     jkzdend, %rsi
    jmp     RestoreRegs
jkzdend:
    pop     %rsi
    ret


# int DoJknzdTests();
#
# This function is similar to the DoJkzdTests function, except that it tests the jknzd instruction.
# For complete details, see documentation of DoJkzdTests() above.
.global DoJknzdTests
.type DoJknzdTests,  @function
DoJknzdTests:
    # Save the necessary registers and prepare their values for the tests
    push    %rsi
    lea     jknzdtestk2, %rsi
    jmp     PrepareRegs

jknzdtestk2:
    # This branch should not be taken
    jknzd   jknzdfinish, %k2

jknzdtestk3:
    knot    %k1, %k1
    # This branch should be taken
    jknzd   jknzdsuccess, %k3
    jmp     jknzdfinish

jknzdsuccess:
    # All tests completed successfully - set return value to 0 (success)
    mov     $0x0, %rax

jknzdfinish:
    # Restore the original register values
    lea     jknzdend, %rsi
    jmp     RestoreRegs
jknzdend:
    pop     %rsi
    ret


# void PrepareRegs(void* returnAddress);
PrepareRegs:
    # Save the necessary GPRs
    push    %rbx
    # Save the necessary mask registers
    kmov    %k1, %ebx
    push    %rbx
    kmov    %k2, %ebx
    push    %rbx
    kmov    %k3, %ebx
    push    %rbx

    # Prepare the mask register values
    movw    $0x0000, %rbx
    kmov    %ebx, %k2
    movw    $0xffff, %rbx
    kmov    %ebx, %k1
    kmov    %ebx, %k3

    # Prepare the return value to indicate failure
    mov     $0x1, %rax
    jmp     *%rsi


# void RestoreRegs(void* returnAddress);
RestoreRegs:
    # Restore the mask registers
    pop     %rbx
    kmov    %ebx, %k3
    pop     %rbx
    kmov    %ebx, %k2
    pop     %rbx
    kmov    %ebx, %k1
    # Restore the GPRs
    pop     %rbx
    jmp     *%rsi

