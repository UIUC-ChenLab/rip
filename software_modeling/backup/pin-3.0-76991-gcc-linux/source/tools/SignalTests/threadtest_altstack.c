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
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <pthread.h>

stack_t main_sigstk;
FILE * log_fd;


void PrintAndCompareAlternateStack(const char* prefix, const stack_t* compare_stack) {
    stack_t sigstk;

    int sigalt_result = sigaltstack(NULL, &sigstk);
    fprintf(log_fd, "%s: sigalt_result == %d {ss_sp=%p; ss_size=%d; ss_flags=%x}\n",
            prefix, sigalt_result, sigstk.ss_sp, (int)sigstk.ss_size, sigstk.ss_flags);
    if (sigalt_result < 0){
        perror("ERROR printing alternate stack");
    }
    if (!sigstk.ss_sp) {
        printf("%s: NO alternate stack\n", prefix);
    }
    if (compare_stack) {
        printf("%s: current stack %s to compare_stack\n", prefix,
                ((sigstk.ss_sp == compare_stack->ss_sp) && sigstk.ss_size == compare_stack->ss_size)?
                "equals":"different");
    }
}

void *doThread(void* arg){
    PrintAndCompareAlternateStack("Thread", &main_sigstk);
    return NULL;
}


int main() {
    int err;

    log_fd = fopen("./threadtest_altstack.log", "w");
    if (log_fd <0 )
        perror("Could not open log file");

    // set current alternate stack
    main_sigstk.ss_sp = malloc(SIGSTKSZ);

    if (main_sigstk.ss_sp == NULL) {
        printf("Could not allocate ss_sp\n");
        return -1;
    }
    main_sigstk.ss_size = SIGSTKSZ;
    main_sigstk.ss_flags = 0;

    err = sigaltstack(&main_sigstk, NULL);
    if (err) {
        perror("Got error from sigaltstack");
    }
    PrintAndCompareAlternateStack("Main", NULL);

    pthread_t tid;
    err = pthread_create(&tid, NULL, doThread, NULL);
    if (err) {
        perror("Could not create a thread\n");
    }

    err = pthread_join(tid, NULL);
    if (err) {
        perror("Could not create a thread\n");
    }

    if (main_sigstk.ss_sp)  free(main_sigstk.ss_sp);

    return 0;
}


