// <ORIGINAL-AUTHOR>: Barak Nirenberg
// <COMPONENT>: os-apis
// <FILE-TYPE>: component public header

/*!
 * @defgroup OS_APIS_SIGNALS Signals
 * @brief Contains signals related os apis
 */

#ifndef OS_APIS_SIGNALS_H
#define OS_APIS_SIGNALS_H

#include "os-apis.h"

/*! @ingroup OS_APIS_SIGNALS
 * Represents a set of signals
 */
typedef UINT64 SIGSET_T;

/*! @ingroup OS_APIS_SIGNALS
 * Specifies an action to OS_SigAction()
 */
struct SIGACTION {
 union {
     void (*_sa_handler)(int);                   //! Signal handle function (old way)
     void (*_sa_sigaction)(int, void *, void *); //! Signal handle function (new way)
     void *_sa_handler_ptr;                      //! Convinience void* pointer to the signal handler.
 } _u;
 SIGSET_T sa_mask;                               //! Mask of signals to block during the handling of the signal
 unsigned long sa_flags;                         //! Additional flags (OS specific).

 void (*sa_restorer)(void);                      //! Signal restorer.
};


/*! @ingroup OS_APIS_SIGNALS
 * Change the action taken by a process on receipt of a specific signal.
 * This function is compatible with POSIX sigaction().
 *
 * @param[in]  signum       The signal to alter its behavior.
 * @param[in]  act          The action to be taken upon signal reception.
 * @param[in]  oldact       The previous action that was taken upon signal reception.
 *
 * @return     Operation status code.
 *
 * @par Availability:
 *   @b O/S:   Linux & OS X*\n
 *   @b CPU:   All\n
 */
OS_RETURN_CODE OS_SigAction(INT signum, const struct SIGACTION *act, struct SIGACTION *oldact);

/*! @ingroup OS_APIS_SIGNALS
 * Change the signal mask, the set of currently blocked signals for the current thread.
 * This function is compatible with POSIX sigprocmask().
 *
 * @param[in]  how          Specifies how to alter the blocked signals mask:
 *                          SIG_BLOCK: The set of blocked signals is the union of the current set and the set argument.
                            SIG_UNBLOCK: The signals in set are removed from the current set of blocked signals.
                                It is legal to attempt to unblock a signal which is not blocked.
                            SIG_SETMASK: The set of blocked signals is set to the argument set.
 * @param[in]  set          The signal set to alter.
 * @param[in]  oldset       The previous blocked signals set.
 *
 * @return     Operation status code.
 *
 * @par Availability:
 *   @b O/S:   Linux & OS X*\n
 *   @b CPU:   All\n
 */
OS_RETURN_CODE OS_SigProcMask(INT how, const SIGSET_T *set, SIGSET_T *oldset);

/*! @ingroup OS_APIS_SIGNALS
 * Temporarily  replaces  the  signal  mask of the calling process with the mask given
 * by mask and then suspends the process until delivery of a signal  whose action is to
 * invoke a signal handler or to terminate a process.
 *
 * @param[in]  mask         The mask to use for the signals
 *
 * @return     Operation status code.
 *
 * @par Availability:
 *   @b O/S:   Linux & OS X*\n
 *   @b CPU:   All\n
 */
OS_RETURN_CODE OS_SigSuspend(const SIGSET_T *mask);

/*! @ingroup OS_APIS_SIGNALS
 * Returns the set of signals that are pending for delivery to the calling thread
 * (i.e., the signals which have been raised while blocked).  The mask of
 * pending signals is returned in set.
 *
 * @param[out] set          Where to store the signal set.
 *
 * @return     Operation status code.
 *
 * @par Availability:
 *   @b O/S:   Linux & OS X*\n
 *   @b CPU:   All\n
 */
OS_RETURN_CODE OS_SigPending(const SIGSET_T *set);

/*! @ingroup OS_APIS_SIGNALS
 * Send signal to a process.
 * This function is compatible with POSIX kill().
 *
 * @param[in]  pid          The process to send signal to.
 * @param[in]  signal       The signal to send.
 *
 * @return     Operation status code.
 *
 * @par Availability:
 *   @b O/S:   Linux & OS X*\n
 *   @b CPU:   All\n
 */
OS_RETURN_CODE OS_SendSignalToProcess(NATIVE_PID pid, INT signal);

/*! @ingroup OS_APIS_SIGNALS
 * Send signal to a particular thread inside a process.
 *
 * @param[in]  pid          The process ID where the thread is running.
 * @param[in]  tid          The thread ID to send the signal to.
 * @param[in]  signal       The signal to send.
 *
 * @return     Operation status code.
 *
 * @par Availability:
 *   @b O/S:   Linux & OS X*\n
 *   @b CPU:   All\n
 */
OS_RETURN_CODE OS_SendSignalToThread(NATIVE_PID pid, NATIVE_TID tid, UINT32 signal);

#endif // OS_APIS_SIGNALS_H
