// <ORIGINAL-AUTHOR>: Barak Nirenberg
// <COMPONENT>: os-apis
// <FILE-TYPE>: component public header

#ifndef OS_APIS_THREAD_DB_H_INCLUDED__
#define OS_APIS_THREAD_DB_H_INCLUDED__

#include "os-apis.h"

/*!
 * @defgroup OS_APIS_THREAD_DB Threads database
 * @brief Contains API for thread tracking
 */

/*! @ingroup OS_APIS_THREAD_DB
 * Register a thread in the threads database.
 *
 * @param[in]  ntid               OS thread ID of the thread to register.
 * @param[out] ptid               Internal ID used to reference this thread in the DB.
 *
 * @par Availability:
 *   - @b O/S:   Windows, Linux & OS X*
 *   - @b CPU:   All
 */
VOID OS_RegisterThread(NATIVE_TID ntid, PIN_TID* ptid);

/*! @ingroup OS_APIS_THREAD_DB
 * Deregister a thread from the threads database and release all the resources
 * used to track this thread (including TLS).
 *
 * @param[in]  ntid               OS thread ID of the thread to deregister.
 *
 * @par Availability:
 *   - @b O/S:   Windows, Linux & OS X*
 *   - @b CPU:   All
 */
VOID OS_DeregisterThread(NATIVE_TID ntid);

/*! @ingroup OS_APIS_THREAD_DB
 * Deregister the current thread from the threads database and release all the resources
 * used to track this thread (including TLS).
 *
 * @par Availability:
 *   - @b O/S:   Windows, Linux & OS X*
 *   - @b CPU:   All
 */
VOID OS_DeregisterCurrentThread(void);

/*! @ingroup OS_APIS_THREAD_DB
 * Find the internal thread ID of a thread by its OS thread ID.
 *
 * @param[in]  ntid               OS thread ID of the thread to look for.
 *
 * @retval     PIN_TID            The internal thread ID of the thread or INVALID_PIN_TID if the thread
 *                                wasn't found.
 *
 * @par Availability:
 *   - @b O/S:   Windows, Linux & OS X*
 *   - @b CPU:   All
 */
PIN_TID OS_PinTidByNativeTid(NATIVE_TID ntid);

#endif // OS_APIS_THREAD_DB_H_INCLUDED__

