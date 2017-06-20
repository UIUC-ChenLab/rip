/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _UAPI_LINUX_SIGNAL_H
#define _UAPI_LINUX_SIGNAL_H
#define SS_ONSTACK 1
#define SS_DISABLE 4

/* Values for si_code */

/* Codes for SIGILL */
#define ILL_NOOP        0       /* if only I knew... */
#define ILL_ILLOPC      1       /* [XSI] illegal opcode */
#define ILL_ILLTRP      2       /* [XSI] illegal trap */
#define ILL_PRVOPC      3       /* [XSI] privileged opcode */
#define ILL_ILLOPN      4       /* [XSI] illegal operand -NOTIMP */
#define ILL_ILLADR      5       /* [XSI] illegal addressing mode -NOTIMP */
#define ILL_PRVREG      6       /* [XSI] privileged register -NOTIMP */
#define ILL_COPROC      7       /* [XSI] coprocessor error -NOTIMP */
#define ILL_BADSTK      8       /* [XSI] internal stack error -NOTIMP */

/* Codes for SIGFPE */
#define FPE_NOOP        0       /* if only I knew... */
#define FPE_FLTDIV      1       /* [XSI] floating point divide by zero */
#define FPE_FLTOVF      2       /* [XSI] floating point overflow */
#define FPE_FLTUND      3       /* [XSI] floating point underflow */
#define FPE_FLTRES      4       /* [XSI] floating point inexact result */
#define FPE_FLTINV      5       /* [XSI] invalid floating point operation */
#define FPE_FLTSUB      6       /* [XSI] subscript out of range -NOTIMP */
#define FPE_INTDIV      7       /* [XSI] integer divide by zero */
#define FPE_INTOVF      8       /* [XSI] integer overflow */

/* Codes for SIGSEGV */
#define SEGV_NOOP       0       /* if only I knew... */
#define SEGV_MAPERR     1       /* [XSI] address not mapped to object */
#define SEGV_ACCERR     2       /* [XSI] invalid permission for mapped object */

/* Codes for SIGBUS */
#define BUS_NOOP        0       /* if only I knew... */
#define BUS_ADRALN      1       /* [XSI] Invalid address alignment */
#define BUS_ADRERR      2       /* [XSI] Nonexistent physical address -NOTIMP */
#define BUS_OBJERR      3       /* [XSI] Object-specific HW error - NOTIMP */

/* Codes for SIGTRAP */
#define TRAP_BRKPT      1       /* [XSI] Process breakpoint -NOTIMP */
#define TRAP_TRACE      2       /* [XSI] Process trace trap -NOTIMP */


#define SA_ONSTACK      0x0001  /* take signal on signal stack */
#define SA_RESTART      0x0002  /* restart system on signal return */
#define SA_RESETHAND    0x0004  /* reset to SIG_DFL when taking signal */
#define SA_NOCLDSTOP    0x0008  /* do not generate SIGCHLD on child stop */
#define SA_NODEFER      0x0010  /* don't mask the signal we're delivering */
#define SA_NOCLDWAIT    0x0020  /* don't keep zombies around */
#define SA_SIGINFO      0x0040  /* signal handler with SA_SIGINFO args */
#define SA_USERTRAMP    0x0100  /* do not bounce off kernel's sigtramp */
/* This will provide 64bit register set in a 32bit user address space */
#define SA_64REGSET     0x0200  /* signal handler with SA_SIGINFO args with 64bit regs information */

#define SIGHUP  1       /* hangup */
#define SIGINT  2       /* interrupt */
#define SIGQUIT 3       /* quit */
#define SIGILL  4       /* illegal instruction (not reset when caught) */
#define SIGTRAP 5       /* trace trap (not reset when caught) */
#define SIGABRT 6       /* abort() */
#define SIGPOLL 7       /* pollable event ([XSR] generated, not supported) */
#define SIGIOT  SIGABRT /* compatibility */
#define SIGEMT  7       /* EMT instruction */
#define SIGFPE  8       /* floating point exception */
#define SIGKILL 9       /* kill (cannot be caught or ignored) */
#define SIGBUS  10      /* bus error */
#define SIGSEGV 11      /* segmentation violation */
#define SIGSYS  12      /* bad argument to system call */
#define SIGPIPE 13      /* write on a pipe with no one to read it */
#define SIGALRM 14      /* alarm clock */
#define SIGTERM 15      /* software termination signal from kill */
#define SIGURG  16      /* urgent condition on IO channel */
#define SIGSTOP 17      /* sendable stop signal not from tty */
#define SIGTSTP 18      /* stop signal from tty */
#define SIGCONT 19      /* continue a stopped process */
#define SIGCHLD 20      /* to parent on child stop or exit */
#define SIGTTIN 21      /* to readers pgrp upon background tty read */
#define SIGTTOU 22      /* like TTIN for output if (tp->t_local&LTOSTOP) */
#define SIGIO   23      /* input/output possible signal */
#define SIGXCPU 24      /* exceeded CPU time limit */
#define SIGXFSZ 25      /* exceeded file size limit */
#define SIGVTALRM 26    /* virtual time alarm */
#define SIGPROF 27      /* profiling time alarm */
#define SIGWINCH 28     /* window size changes */
#define SIGINFO 29      /* information request */
#define SIGUSR1 30      /* user defined signal 1 */
#define SIGUSR2 31      /* user defined signal 2 */

#define SIG_DFL         (void (*)(int))0
#define SIG_IGN         (void (*)(int))1
#define SIG_HOLD        (void (*)(int))5
#define SIG_ERR         ((void (*)(int))-1)

/*
 * Flags for sigprocmask:
 */
#define SIG_BLOCK       1       /* block specified signal set */
#define SIG_UNBLOCK     2       /* unblock specified signal set */
#define SIG_SETMASK     3       /* set specified signal set */

/* POSIX 1003.1b required values. */
#define SI_USER         0x10001 /* [CX] signal from kill() */
#define SI_QUEUE        0x10002 /* [CX] signal from sigqueue() */
#define SI_TIMER        0x10003 /* [CX] timer expiration */
#define SI_ASYNCIO      0x10004 /* [CX] aio request completion */
#define SI_MESGQ        0x10005 /* [CX] from message arrival on empty queue */

typedef __uint32_t    __darwin_sigset_t;      /* [???] signal set */

/*
 * Signal alt stack
 */

#ifndef _STRUCT_SIGALTSTACK
#if __DARWIN_UNIX03
#define _STRUCT_SIGALTSTACK     struct __darwin_sigaltstack
#else /* !__DARWIN_UNIX03 */
#define _STRUCT_SIGALTSTACK     struct sigaltstack
#endif /* __DARWIN_UNIX03 */
_STRUCT_SIGALTSTACK
{
        void            *ss_sp;         /* signal stack base */
        __darwin_size_t ss_size;        /* signal stack length */
        int             ss_flags;       /* SA_DISABLE and/or SA_ONSTACK */
};
#endif /* _STRUCT_SIGALTSTACK */

#include "mac_mcontext.h"

/*
 *  User context
 */

#ifndef _STRUCT_UCONTEXT
#if __DARWIN_UNIX03
#define _STRUCT_UCONTEXT        struct __darwin_ucontext
#else /* !__DARWIN_UNIX03 */
#define _STRUCT_UCONTEXT        struct ucontext
#endif /* __DARWIN_UNIX03 */
_STRUCT_UCONTEXT
{
        int                     uc_onstack;
        __darwin_sigset_t       uc_sigmask;     /* signal mask used by this context */
        _STRUCT_SIGALTSTACK     uc_stack;       /* stack used by this context */
        _STRUCT_UCONTEXT        *uc_link;       /* pointer to resuming context */
        __darwin_size_t         uc_mcsize;      /* size of the machine context passed in */
        _STRUCT_MCONTEXT        *uc_mcontext;   /* pointer to machine specific context */
#ifdef _XOPEN_SOURCE
        _STRUCT_MCONTEXT        __mcontext_data;
#endif /* _XOPEN_SOURCE */
};
#endif /* _STRUCT_UCONTEXT */

#ifndef _UCONTEXT_T
#define _UCONTEXT_T
typedef _STRUCT_UCONTEXT        ucontext_t;     /* [???] user context */
#endif /* _UCONTEXT_T */


typedef __darwin_sigset_t sigset_t;
typedef void (*__sighandler_t)(int);
typedef _STRUCT_SIGALTSTACK stack_t;

typedef void __restorefn_t(void);
typedef __restorefn_t __user *__sigrestore_t;

union sigval {
        /* Members as suggested by Annex C of POSIX 1003.1b. */
        int     sival_int;
        void    *sival_ptr;
};

typedef struct siginfo {
        int     si_signo;               /* signal number */
        int     si_errno;               /* errno association */
        int     si_code;                /* signal code */
        pid_t   si_pid;                 /* sending process */
        uid_t   si_uid;                 /* sender's ruid */
        int     si_status;              /* exit value */
        void    *si_addr;               /* faulting instruction */
        union sigval si_value;          /* signal value */
        long    si_band;                /* band event for SIGPOLL */
        unsigned long   __pad[7];       /* Reserved for Future Use */
} siginfo_t;

#endif
