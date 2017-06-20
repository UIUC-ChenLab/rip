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
include asm_macros.inc

PROLOGUE

PUBLIC getFlags
PUBLIC modifyFlags

.code

modifyFlags PROC EXPORT
    ret
modifyFlags ENDP

; Sets the flags register to the first argument of this function
; then call modifyFlags() and returns the value of the flags register
; after the invocation.
getFlags PROC
    BEGIN_STACK_FRAME
    NATIVE_SIZE_SUFFIX pushf
    mov RETURN_REG, PARAM1
    push RETURN_REG
    NATIVE_SIZE_SUFFIX popf
    call modifyFlags
    NATIVE_SIZE_SUFFIX pushf
    pop RETURN_REG
    NATIVE_SIZE_SUFFIX popf
    END_STACK_FRAME
    ret
getFlags ENDP

end
