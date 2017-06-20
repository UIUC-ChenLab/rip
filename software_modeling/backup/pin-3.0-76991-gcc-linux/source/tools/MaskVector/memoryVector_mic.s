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

.data

.extern zeroVector
.extern memValues
.extern dpIndices
.extern spIndices

# The zmmSaveArea requires 128 bytes and a 64 byte padding since the
# vmovdqa64 instruction requires a 64-byte-aligned address
zmmSaveArea:
.space 192

.text

# void DoVgatherTest();
#
# This function calls the single and double precision forms of vgather. The tool should inspect the memory vector
# contents and the register values before and after each vgather instruction.
#
# Register usage:
# rax   - used for storing and loading the mask registers
# rbx   - used for holding a pointer to the memory vector values
# rcx   - used for storing and loading values to the zmm registers
# rdx   - used for holding a pointer to the zmm save area
# rsi   - used for control flow
# zmm2  - target vector for the vgather instructions
# zmm3  - index vetor for the vgather instructions
# k1    - holds a full mask for manipulating the vector registers
# k2    - used as the test mask register for the vgather instructions
.global DoVgatherTest
.type DoVgatherTest,  @function
DoVgatherTest:
    # Save the necessary registers and prepare their values for the tests
    push    %rsi
    lea     vgatherbegin, %rsi
    jmp     PrepareRegs

vgatherbegin:
    # Test the double-precision vgather
    lea     dpIndices, %rcx
    vmovdqa64   (%rcx), %zmm3 {%k1}
    mov     gatherMask, %rax
    kmov    %eax, %k2
    vgatherdpd  (%rbx, %zmm3, 8), %zmm2 {%k2}

    # Test the single-precision vgather
    lea     spIndices, %rcx
    vmovdqa64   (%rcx), %zmm3 {%k1}
    mov     gatherMask, %rax
    kmov    %eax, %k2
    vgatherdps  (%rbx, %zmm3, 4), %zmm2 {%k2}

    # Restore the original register values
    lea     vgatherend, %rsi
    jmp     RestoreRegs

vgatherend:
    pop     %rsi
    ret


# void DoScatterTest();
#
# This function is similar to the DoVgatherTest function, except that it tests the vscatter instruction.
# For complete details, see documentation of DoVgatherTest() above.
.global DoVscatterTest
.type DoVscatterTest,  @function
DoVscatterTest:
    # Save the necessary registers and prepare their values for the tests
    push    %rsi
    lea     vscatterbegin, %rsi
    jmp     PrepareRegs

vscatterbegin:
    # Test the double-precision vgather
    lea     dpIndices, %rcx
    vmovdqa64   (%rcx), %zmm3 {%k1}
    mov     scatterMask, %rax
    kmov    %eax, %k2
    vscatterdpd %zmm2, (%rbx, %zmm3, 8) {%k2}

    # Test the single-precision vgather
    lea     spIndices, %rcx
    vmovdqa64   (%rcx), %zmm3 {%k1}
    mov     scatterMask, %rax
    kmov    %eax, %k2
    vscatterdps %zmm2, (%rbx, %zmm3, 8) {%k2}

    # Restore the original register values
    lea     vscatterend, %rsi
    jmp     RestoreRegs

vscatterend:
    pop     %rsi
    ret


# void PrepareRegs(void* returnAddress);
PrepareRegs:
    # Save the necessary GPRs
    push    %rax
    push    %rbx
    push    %rcx
    push    %rdx

    # Save the necessary mask registers
    kmov    %k1, %eax
    push    %rax
    kmov    %k2, %eax
    push    %rax

    # Prepare the mask registers
    # Full mask
    mov     fullmask, %rax
    kmov    %eax, %k1
    # The test register (k2) will be set during the test itself

    # Allign the zmmSaveArea
    lea     zmmSaveArea, %rdx
    add     $0x40, %rdx
    and     $0xffffffffffffffc0, %rdx
    # Save the necessary vector registers
    vmovdqa64   %zmm2, (%rdx) {%k1}
    add         $0x40, %rdx
    vmovdqa64   %zmm3, (%rdx) {%k1}

    # Zero out the target vector register
    lea         zeroVector, %rcx
    vmovdqa64   (%rcx), %zmm2 {%k1}

    # Set a pointer to the memory vector values
    lea     memValues, %rbx
    jmp     *%rsi


# void RestoreRegs(void* returnAddress);
RestoreRegs:
    # Allign the zmmSaveArea
    lea     zmmSaveArea, %rdx
    add     $0x40, %rdx
    and     $0xffffffffffffffc0, %rdx
    # Restore the vector registers
    vmovdqa64   (%rdx), %zmm2 {%k1}
    add         $0x40, %rdx
    vmovdqa64   (%rdx), %zmm3 {%k1}

    # Restore the mask registers
    pop     %rax
    kmov    %eax, %k2
    pop     %rax
    kmov    %eax, %k1

    # Restore the GPRs
    pop     %rdx
    pop     %rcx
    pop     %rbx
    pop     %rax
    jmp     *%rsi
