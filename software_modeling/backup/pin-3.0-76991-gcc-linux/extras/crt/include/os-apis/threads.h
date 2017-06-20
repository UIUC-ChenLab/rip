// <ORIGINAL-AUTHOR>: Yoav Levy
// <COMPONENT>: os-apis
// <FILE-TYPE>: component public header
/// @file threads.h

/*!
 * @defgroup OS_APIS_THREAD Threads
 * @brief Contains thread-related os apis
 */

#ifndef OS_APIS_THREAD_H
#define OS_APIS_THREAD_H

#define OS_APIS_TLS_SLOT_TLS_AND_STACK_START_ADDRESS 4

/*! @ingroup OS_APIS_THREAD
 * Create a new thread in the current process.
 *
 * @param[in]   ThreadMainFunction Thread start address
 * @param[in]   ThreadParam        Thread optional parameter
 * @param[out]  td                 The descriptor of newly created thread.
 *
 * @retval      OS_RETURN_CODE_NO_ERROR             If the operation succeeded
 * @retval      OS_RETURN_CODE_THREAD_CREATE_FAILED If the operation Failed
 * @return      Operation status code.
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X*\n
 *   @b CPU:   All\n
 */
OS_RETURN_CODE OS_CreateThread(INT (*ThreadMainFunction)(VOID*), VOID *ThreadParam, NATIVE_TID* td);

/*! @ingroup OS_APIS_THREAD
 * Causes a running thread to exit.
 *
 * @param[in]  td                  Thread descriptor
 *
 * @retval      OS_RETURN_CODE_NO_ERROR             If the operation succeeded
 * @retval      OS_RETURN_CODE_THREAD_EXIT_FAILED   If the operation Failed
 * @return      Operation status code.
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X*\n
 *   @b CPU:   All\n
 */
OS_RETURN_CODE OS_ExitThread(NATIVE_TID td);

/*! @ingroup OS_APIS_THREAD
 * Suspends a running thread.
 *
 * @param[in]  td                  Thread descriptor
 *
 * @retval      OS_RETURN_CODE_NO_ERROR                 If the operation succeeded
 * @retval      OS_RETURN_CODE_THREAD_SUSPEND_FAILED    If the operation Failed
 * @return      Operation status code.
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X*\n
 *   @b CPU:   All\n
 */
OS_RETURN_CODE OS_SuspendThread(NATIVE_TID td);

/*! @ingroup OS_APIS_THREAD
 * Resumes running thread.
 *
 * @param[in]  td                  Thread descriptor
 *
 * @retval      OS_RETURN_CODE_NO_ERROR             If the operation succeeded
 * @retval      OS_RETURN_CODE_THREAD_RESUME_FAILED If the operation Failed
 * @return      Operation status code.
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X*\n
 *   @b CPU:   All\n
 */
OS_RETURN_CODE OS_ResumeThread(NATIVE_TID td);

/*! @ingroup OS_APIS_THREAD
 * Sends thread to sleep.
 *
 * @param[in]  interval            Interval to sleep in milli-seconds.
 *
 * @retval      OS_RETURN_CODE_NO_ERROR             If the operation succeeded
 * @retval      OS_RETURN_CODE_THREAD_SLEEP_FAILED  If the operation Failed
 * @return      Operation status code.
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X*\n
 *   @b CPU:   All\n
 */
OS_RETURN_CODE OS_Sleep(INT interval);

/*! @ingroup OS_APIS_THREAD
 * Retrieves the current thread's handle.
 *
 * @param[out]  id                 Address of handle container variable
 *
 * @retval      OS_RETURN_CODE_NO_ERROR             If the operation succeeded
 * @retval      OS_RETURN_CODE_THREAD_QUERY_FAILED  If the operation Failed
 * @return      Operation status code.
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X*\n
 *   @b CPU:   All\n
 */
OS_RETURN_CODE OS_GetTid(NATIVE_TID* id);

/*! @ingroup OS_APIS_THREAD
 * Pre-empts the thread specified by the running thread.
 *
 * @retval      OS_RETURN_CODE_NO_ERROR             If the operation succeeded
 * @retval      OS_RETURN_CODE_THREAD_SLEEP_FAILED  If the operation Failed
 * @return      Operation status code.
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X*\n
 *   @b CPU:   All\n
 */
OS_RETURN_CODE OS_Yield(void);

/*! @ingroup OS_APIS_THREAD
 * Raise an exception.
 *
 * @param[in]  td   Thread descriptor
 * @param[in]  code Exception type
 *
 * @retval      OS_RETURN_CODE_NO_ERROR             If the operation succeeded
 * @retval      OS_RETURN_CODE_THREAD_SLEEP_FAILED  If the operation Failed
 * @return      Operation status code.
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X*\n
 *   @b CPU:   All\n
 */
OS_RETURN_CODE OS_RaiseException(NATIVE_TID td, UINT32 code);

/*! @ingroup OS_APIS_THREAD
 * Register bsd thread start callback.
 *
 * @param[in]  thread_start       Callback function for thread start
 * @param[in]  start_wqthread     Callback function for work-queue thread start
 * @param[in]  pthread_size       The size of a pthread object.
 * @param[in]  arg3               OS specific argument (depends on the version of OS X*).
 * @param[in]  arg4               OS specific argument (depends on the version of OS X*).
 * @param[in]  arg5               OS specific argument (depends on the version of OS X*).
 * @param[out] pthread_features   Return value from the bsdthread_register syscall.
 *                                This is a bitmask of supported kernel pthread features.
 *
 * @retval      OS_RETURN_CODE_NO_ERROR             If the operation succeeded
 * @retval      OS_RETURN_CODE_THREAD_CREATE_FAILED If the operation Failed
 * @return      Operation status code.
 *
 * @par Availability:
 *   @b O/S:   OS X*\n
 *   @b CPU:   All\n
 */
OS_RETURN_CODE OS_RegisterMacThreadStartFunction(
                                              void* thread_start,
                                              void* start_wqthread,
                                              int pthread_size, // size of pthread struct
                                              ADDRINT arg3,
                                              ADDRINT arg4,
                                              ADDRINT arg5,
                                              int* pthread_features);

#endif // file guard
