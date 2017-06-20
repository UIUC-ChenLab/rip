// <ORIGINAL-AUTHOR>: Barak Nirenberg
// <COMPONENT>: os-apis
// <FILE-TYPE>: component public header

#ifndef OS_APIS_RW_LOCK_H__
#define OS_APIS_RW_LOCK_H__

#include "os-apis.h"

/*!
 * @defgroup OS_APIS_RW_LOCK Readers writers lock
 * @brief Implementation of readers writers lock.
 */

/*!
 * This is an opaque struct for readers/writers lock.
 * This struct should be used with the functions declared in this header.
 */
typedef struct
{
    OS_SPINLOCK_TYPE lock;
    OS_SPINLOCK_TYPE readers;
#ifndef TARGET_WINDOWS
    OS_SPINLOCK_TYPE spinlock_fork_count;
#endif
} OS_APIS_RW_LOCK_T;

/*!
 * Static initializer for OS_APIS_RW_LOCK_T type.
 */
#define OS_APIS_RW_LOCK_INITIALIZER {(OS_SPINLOCK_TYPE)0, (OS_SPINLOCK_TYPE)0}

/*! @ingroup OS_APIS_RW_LOCK
 * Acquires the lock for writer.
 * Blocks until the writer lock is acquired.
 *
 * @param[in]  lock         The lock to acquire
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X*\n
 *   @b CPU:   All\n
 */
void OS_RWLockAcquireWrite(OS_APIS_RW_LOCK_T* lock);

/*! @ingroup OS_APIS_RW_LOCK
 * Releases the lock for writer.
 *
 * @param[in]  lock         The lock to release
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X*\n
 *   @b CPU:   All\n
 */
void OS_RWLockReleaseWrite(OS_APIS_RW_LOCK_T* lock);

/*! @ingroup OS_APIS_RW_LOCK
 * Acquires the lock for reader.
 * Blocks until the reader lock is acquired.
 *
 * @param[in]  lock         The lock to acquire
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X*\n
 *   @b CPU:   All\n
 */
void OS_RWLockAcquireRead(OS_APIS_RW_LOCK_T* lock);

/*! @ingroup OS_APIS_RW_LOCK
 * Releases the lock for reader.
 *
 * @param[in]  lock         The lock to release
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X*\n
 *   @b CPU:   All\n
 */
void OS_RWLockReleaseRead(OS_APIS_RW_LOCK_T* lock);

/*! @ingroup OS_APIS_RW_LOCK
 * Releases the lock that was acquired.
 * The lock kind that was acquired (whether its read or write)
 * is determined by this function.
 *
 * @param[in]  lock         The lock to release
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X*\n
 *   @b CPU:   All\n
 */
void OS_RWLockRelease(OS_APIS_RW_LOCK_T* l);

#endif // OS_APIS_RW_LOCK_H__
