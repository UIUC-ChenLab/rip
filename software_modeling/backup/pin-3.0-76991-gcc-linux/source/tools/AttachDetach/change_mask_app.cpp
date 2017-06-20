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
 * This application checks the correctness of the retrieve and alteration
 * of the thread sigmask when a tool retrieves / alters it.
 */

#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <cstdio>
#include <errno.h>
#include <cstring>
#include <cstdlib>
#include <semaphore.h>
#include <sys/syscall.h>


static sem_t mutex, mutex1;
static pthread_t one_tid, two_tid;
static FILE * fd_signals;
static char * FILE_NAME = const_cast<char *>("signal_list.txt");
static int MAX_SIZE = 128; /*maximum line size*/
static int syncPipe[2];
static volatile int iteration = 0;


extern "C" bool WaitChangeSigmask()
{
   return false;
}


void EmptySignalHandler(int param)
{
}

int sem_wait_check_errno(sem_t *sem)
{
    do
    {
        int r = sem_wait(sem);
        if (0 == r)
        {
            return r;
        }
    }
    while (EINTR == errno);
    perror("sem_wait");
    abort();
    return -1;
}

int sem_post_check_errno(sem_t *sem)
{
    int r = sem_post(sem);
    if (0 != r)
    {
        perror("sem_wait");
        abort();
    }
    return 0;
}

/*
 * block all the signals relevant to this test
 * Note that we don't want to block SIGTERM, SIGINT and such because we want
 * to allow the test termination in case of cancellation
 */
void BlockUserSignals()
{
    sigset_t sigmask;
    sigemptyset(&sigmask);
    sigaddset(&sigmask, SIGUSR1);
    sigaddset(&sigmask, SIGUSR2);
    pthread_sigmask(SIG_BLOCK, &sigmask, NULL);
}


/*
 * block only the signals in the list: "signalsListToBlock"
 */
void BlockSignals(int signalsListToBlock[] , int len, sigset_t * sigmask)
{
    sigemptyset(sigmask);
    int i;
    for(i=0; i< len; ++i)
        sigaddset(sigmask, signalsListToBlock[i]);
    pthread_sigmask(SIG_SETMASK, sigmask, NULL);
}


/*
 *  A thread function that processes SIGUSR1 and SIGUSR2 signals sent by the SignalSender thread function
 */
void * SignalReceiver(void *arg)
{
    fd_signals = fopen(FILE_NAME, "wt");
    int sigList[1] = {SIGUSR2};
    sigset_t sigmask;
    BlockSignals(sigList, 1, &sigmask);
    signal(SIGUSR2, EmptySignalHandler);
    signal(SIGUSR1, EmptySignalHandler);
    sem_post_check_errno(&mutex);
    while (iteration<10)
    { 
        int numSigReceived=0;
        pthread_sigmask(SIG_SETMASK, NULL, &sigmask);

        time_t start = time(NULL);

        // wait for the signal for at most 2 seconds
        while ((time(NULL) - start) < 2)
        {
            if (0 != sigpending(&sigmask))
            {
                perror("sigpending");
                exit(2);
            }
            if (sigismember(&sigmask, SIGUSR1) || sigismember(&sigmask, SIGUSR2))
            {
                // sigwait will not block since we already have signal pending
                sigwait(&sigmask, &numSigReceived);
                break;
            }
            sched_yield();
        }

        signal(SIGUSR2, EmptySignalHandler);
        signal(SIGUSR1, EmptySignalHandler);

        if(numSigReceived == SIGUSR2)
        {
            iteration++;
            fprintf(fd_signals, "%d", 2 );
        }
        if(numSigReceived == SIGUSR1)
        {
            iteration++;
            fprintf(fd_signals, "%d", 1 );
        }
        sem_post_check_errno(&mutex);
        sem_wait_check_errno(&mutex1);
    }
    fclose(fd_signals);
    return NULL;
}


/*
 *  Send repeatedly signals (SIGUSR1 and SIGUSR2) to the thread which starts execution by invoking the function
 *  SignalReceiver
 */
void * SignalSender(void *arg)
{
    bool wasSigmaskChanged = false;
    sigset_t sigmask;
    int sigList[2] = {SIGUSR1, SIGUSR2};
    BlockSignals(sigList, 2, &sigmask);
    sem_wait_check_errno(&mutex);
    do
    {
        pthread_kill(two_tid, SIGUSR2); /* Delivers a signal*/
        pthread_kill(two_tid, SIGUSR1); /* Delivers a signal*/

        if(iteration==2 && !wasSigmaskChanged)
        {
            wasSigmaskChanged = true;
            close(syncPipe[1]); // close the write side - releasing the child process to start PIN
            while(!WaitChangeSigmask()) sched_yield();
        }

        sem_post_check_errno(&mutex1);
        sem_wait_check_errno(&mutex);
    }
    while (pthread_kill(two_tid, 0) == 0); // while two_tid is alive
    return NULL;
}


/*
 * Main function
 *
 * Expected arguments:
 * 1 - output file name
 * 2 - Pin executable
 * 3 - "-slow_asserts" (optional)
 * 4 - tool name
 */
int main(int argc, char * argv[])
{
    pid_t parentPid = getpid();

    bool validNumberOfArgs = true;
    if (4 == argc)
    {
        for (int i = 0; i < argc; ++i)
        {
            if (0 == strcmp("-slow_asserts", argv[i])) // not expecting -slow_asserts
            {
                validNumberOfArgs = false;
                break;
            }
        }
    }
    else if (5 == argc)
    {
        if (0 != strcmp("-slow_asserts", argv[3])) // expecting -slow_asserts at position 3
        {
            validNumberOfArgs = false;
        }
    }
    else validNumberOfArgs = false; // illegal number of arguments

    if (!validNumberOfArgs)
    {
        fprintf(stderr, "Usage: %s <output file> <PIN exe> [-slow_asserts] <Tool name>\n", argv[0]);
        return 1;
    }

    FILE_NAME = argv[1];

    if (0 != pipe(syncPipe))
    {
        perror("pipe");
        return 1;
    }
    pid_t pid = fork();
    BlockUserSignals();

    if (0 != pid)
    {
        // In the parent process.
        close(syncPipe[0]); // close the read side of the pipe
        sem_init(&mutex, 0, 0);
        sem_init(&mutex1, 0, 0);

        /*
         * create two threads, one which sends signals to the other threads, which receives them.
         */
        pthread_create(&one_tid, NULL, SignalSender, NULL);
        pthread_create(&two_tid, NULL, SignalReceiver, NULL);

        /*
         * suspended execution until the two threads terminate
         */
        pthread_join(two_tid,NULL);
        sem_post_check_errno(&mutex); // release mutex as one_tid may wait on it
        pthread_join(one_tid, NULL);

        /*
         * cleanup
         */
        sem_destroy(&mutex); /* destroy semaphore */
        sem_destroy(&mutex1); /* destroy semaphore */
    }
    else
    {
        // In the child process.
        char dummy;
        close(syncPipe[1]); // close the write side of the pipe
        read(syncPipe[0], &dummy, sizeof(dummy)); // wait for parent
        close(syncPipe[0]); // close the read side as we're done
        char attachPid[MAX_SIZE];
        sprintf(attachPid, "%d", parentPid);

        char* args[9];
        int argsco = 0;
        int argsci = 2; // input argument #2 is the Pin executable (see documentation at the top of the main function)
        args[argsco++] = argv[argsci++]; // pin executable
        if (argc == 5)
        {
            char* slow_assert = args[argsco++] = argv[argsci++]; // -slow_asserts (if present)
        }
        args[argsco++] = "-probe";
        args[argsco++] = "-pid";
        args[argsco++] = attachPid;
        args[argsco++] = "-t";
        args[argsco++] = argv[argsci++]; // tool name
        args[argsco++] = NULL; // end

        /*
         * Pin attach to the parent thread.
         * never return
         */
        execv(args[0], args);
        perror("execv");
        return 10;
    }
    return 0;
}
