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
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

volatile int iteration_main = 0;
volatile int iteration_second = 0;
volatile bool shouldExit = false;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Prevent inlining of these functions
#define EMPTY_FUNC(name) \
	extern "C" void name(); \
	__asm__(".globl " #name "\n .type " #name ", @function\n " \
	        #name ":\n ret\n");

EMPTY_FUNC(SecondThreadIterationCheckpoint1)
EMPTY_FUNC(SecondThreadIterationCheckpoint2)
EMPTY_FUNC(SecondThreadIterationCheckpoint3)
EMPTY_FUNC(MainThreadIterationCheckpoint)

void* SecondThread(void* arg)
{
    for (iteration_second = 0; iteration_second < 100; )
    {
        SecondThreadIterationCheckpoint1();
        pthread_mutex_unlock(&mutex);
        iteration_second++;
        SecondThreadIterationCheckpoint2();
        pthread_mutex_lock(&mutex);
        SecondThreadIterationCheckpoint3();

        while (iteration_second > iteration_main)
        {
            pthread_mutex_unlock(&mutex);
            sched_yield();
            pthread_mutex_lock(&mutex);
        }
    }
    pthread_mutex_unlock(&mutex);

    shouldExit = true;
    return NULL;
}


int main()
{
    pthread_t thd;

    pthread_mutex_lock(&mutex);

    pthread_create(&thd, NULL, SecondThread, NULL);

    do
    {
        MainThreadIterationCheckpoint();
        pthread_mutex_lock(&mutex);
        iteration_main++;
        while (iteration_main >= iteration_second && !shouldExit)
        {
            pthread_mutex_unlock(&mutex);
            sched_yield();
            pthread_mutex_lock(&mutex);
        }
        pthread_mutex_unlock(&mutex);
    }
    while (!shouldExit);

    printf("Application finished successfully!\n");

    return 0;
}
