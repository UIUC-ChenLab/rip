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
 * void DoUnalign()
 */
    .text
    .align 16
    .global DoUnalign
    .proc DoUnalign
DoUnalign:
    .prologue
    .body

    // Set UM.ac (alignment check).  This should force an unaligned access to fault.
    //
    mov r14 = psr.um;;
    or r14 = 0x8, r14;;
    mov psr.um = r14;;

    movl r14 = Var+1;;
    st8 [r14] = r14         // Do an unaligned access
    br.ret.sptk.many b0;;
    .endp DoUnalign


    .data
    .align 8
Var:
    .long 0


/*
 * void DoIllegal()
 */
    .text
    .align 16
    .global DoIllegal
    .proc DoIllegal
DoIllegal:
    .prologue
    .body
    nop 0;;
    nop 1;;
    nop 2;;
    mov ar.bsp = r0;;   // This is an illegal instruction.
    nop 0;;
    nop 1;;
    nop 2;;
    br.ret.sptk.many b0;;
    .endp DoIllegal


/*
 * void DoDiv0()
 */
    .text
    .align 16
    .global DoDiv0
    .proc DoDiv0
DoDiv0:
    .prologue
    .body

    // Clear all the trap bits in FPSR, which enables all FP exceptions.
    //
    mov r14 = ar.fpsr;;
    nop 0;;
    nop 1;;
    nop 2;;
    dep r14 = 0, r14, 0, 6;;
    nop 0;;
    nop 1;;
    nop 2;;
    mov ar.fpsr = r14;
    nop 0;;
    nop 1;;
    nop 2;;

    frcpa f6, p6 = f1, f0   // Divide by zero

    // The "zero divide" exception should be delivered with PC at the 'frcpa' instruction.

    br.ret.sptk.many b0;;
    .endp DoDiv0


/*
 * void DoInexact()
 */
    .text
    .align 16
    .global DoInexact
    .proc DoInexact
DoInexact:
    .prologue
    .body

    // Clear all the trap bits in FPSR, which enables all FP exceptions.
    //
    mov r14 = ar.fpsr;;
    nop 0;;
    nop 1;;
    nop 2;;
    dep r14 = 0, r14, 0, 6;;
    nop 0;;
    nop 1;;
    nop 2;;
    mov ar.fpsr = r14;
    nop 0;;
    nop 1;;
    nop 2;;

    movl    r14 = 0x3fe0000000000000;;  // r14 = 0.5
    setf.d  f6 = r14;;                  // f6 = 0.5
    fcvt.fx f6 = f6                     // convert to integer, raise "inexact" fault

    // The "inexact" exception should be delivered wit PC at the instruction following 'fcvt.fx'.

    br.ret.sptk.many b0;;
    .endp DoInexact


/*
 * void DoBreak()
 */
    .text
    .align 16
    .global DoBreak
    .proc DoBreak
DoBreak:
    .prologue
    .body
    break 0xccccc
    .endp DoBreak
