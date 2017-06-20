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
#ifdef TARGET_MAC
#define NAME(x) _##x
#else
#define NAME(x) x
#endif

.global NAME(getStartNop), NAME(getEndNop), NAME(getBeforeFunc), NAME(getAfterFunc)
#ifndef TARGET_MAC
.type getStartNop, @function
.type getEndNop, @function
.type getBeforeFunc, @function
.type getAfterFunc, @function
#endif
NAME(getStartNop):
	lea NAME(before_nop_label)(%rip), %rax
    ret

NAME(getEndNop):
	lea NAME(after_nop_label)(%rip), %rax
	ret

NAME(getBeforeFunc):
	lea NAME(before_code_label)(%rip), %rax
	ret

NAME(getAfterFunc):
	lea NAME(after_code_label)(%rip), %rax
	ret

NAME(before_nop_label):
	nop
NAME(after_nop_label):
NAME(before_code_label):
	ret
NAME(after_code_label):
