; BEGIN_LEGAL 
; Intel Open Source License 
; 
; Copyright (c) 2002-2016 Intel Corporation. All rights reserved.
;  
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions are
; met:
; 
; Redistributions of source code must retain the above copyright notice,
; this list of conditions and the following disclaimer.  Redistributions
; in binary form must reproduce the above copyright notice, this list of
; conditions and the following disclaimer in the documentation and/or
; other materials provided with the distribution.  Neither the name of
; the Intel Corporation nor the names of its contributors may be used to
; endorse or promote products derived from this software without
; specific prior written permission.
;  
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
; ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
; LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
; A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE INTEL OR
; ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
; SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
; LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
; DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
; THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
; (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
; OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; END_LEGAL
PUBLIC SupportsAvx2
PUBLIC Do_Xsave
PUBLIC Do_Fxsave
PUBLIC Do_Xrstor
PUBLIC Do_Fxrstor


.code
SupportsAvx2 PROC
    push    rbp
    mov     rbp, rsp

    push    rbx
    push    rcx
    push    rdx
    push    rsi

    mov     rax, 1      

    cpuid

    and ecx, 0018000000h
    cmp ecx, 0018000000h 
    jne $lNOT_SUPPORTED 
    mov ecx, 0          
    
    BYTE 00Fh
    BYTE 001h
    BYTE 0D0h
    and eax, 6
    cmp eax, 6        
    jne $lNOT_SUPPORTED
    mov ecx, 0          
    mov     rax, 7
    cpuid
    and ebx, 010h
    cmp ebx, 010h 
    jne $lNOT_SUPPORTED  
    mov rax, 1
    jmp $lDONE3
$lNOT_SUPPORTED:
    mov rax, 0
$lDONE3:
    pop    rsi
    pop    rdx
    pop    rcx
    pop    rbx

    mov     rsp, rbp
    pop     rbp
    ret
SupportsAvx2 ENDP

.code
Do_Xsave PROC
    xor rdx,rdx
    mov rax,7
 
    ret
Do_Xsave ENDP

.code
Do_Fxsave PROC
    fxsave xmmword ptr[rcx]
    ret
Do_Fxsave ENDP

.code
Do_Xrstor PROC
    xor rdx,rdx
    mov rax,7
    
    ret
Do_Xrstor ENDP

.code
Do_Fxrstor PROC
    fxrstor xmmword ptr[rcx]
    ret
Do_Fxrstor ENDP

end
