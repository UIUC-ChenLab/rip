// <ORIGINAL-AUTHOR>: Barak Nirenberg
// <COMPONENT>: os-apis
// <FILE-TYPE>: component public header

#ifndef OS_APIS_MUTEX_H_INCLUDED_
#define OS_APIS_MUTEX_H_INCLUDED_

/*!
 * @defgroup OS_APIS_MUTEX Mutex
 * @brief Implementation of mutex lock.
 */

typedef UINT32 OS_SPINLOCK_TYPE;

typedef enum _OS_APIS_MUTEX_KIND {
    OS_MUTEX_DEPTH_SIMPLE = 0, //!< This lock can only be acquired once, no matter if the same thread tried to acquire it twice
    OS_MUTEX_DEPTH_RECURSIVE   //!< Recursive lock that can be acquired recursively by the same thread.
} OS_MUTEX_DEPTH;

/*! @ingroup OS_APIS_MUTEX
 * This type holds a representation of a mutex.
 *
 * @par Availability:
 *   - @b O/S:   Windows, Linux & OS X*
 *   - @b CPU:   All
 */
typedef struct _OS_APIS_MUTEX_TYPE {
    OS_MUTEX_DEPTH kind;
    OS_SPINLOCK_TYPE spinlock;
    NATIVE_TID owner;
    UINT32 depth;
#ifndef TARGET_WINDOWS
    OS_SPINLOCK_TYPE spinlock_fork_count;
#endif
} OS_MUTEX_TYPE;

#define OS_APIS_MUTEX_DEPTH_SIMPLE_INITIALIZER {OS_MUTEX_DEPTH_SIMPLE ,(OS_SPINLOCK_TYPE)0, (NATIVE_TID)0, 0}

#define OS_APIS_MUTEX_DEPTH_RECURSIVE_INITIALIZER {OS_MUTEX_DEPTH_RECURSIVE ,(OS_SPINLOCK_TYPE)0, (NATIVE_TID)0, 0}

/*! @ingroup OS_APIS_MUTEX
 * Initialize a mutex.
 * A mutex must be initialized before being used.
 * Use this function to initialize the mutex or use one of the static initializers.
 *
 * @param[in]  lock               The mutex to initialize.
 *
 * @par Availability:
 *   - @b O/S:   Windows, Linux & OS X*
 *   - @b CPU:   All
 */
void OS_MutexInit(volatile OS_MUTEX_TYPE *lock);

/*! @ingroup OS_APIS_MUTEX
 * Initialize a recursive mutex.
 * A mutex must be initialized before being used.
 * Use this function to initialize a recursive mutex or use one of the static initializers.
 *
 * @param[in]  lock               The mutex to initialize.
 *
 * @par Availability:
 *   - @b O/S:   Windows, Linux & OS X*
 *   - @b CPU:   All
 */
void OS_MutexRecursiveInit(volatile OS_MUTEX_TYPE *lock);

/*! @ingroup OS_APIS_MUTEX
 * Destroys a mutex after it is no longer in use.
 *
 * @param[in]  lock               The mutex to destroy.
 *
 * @par Availability:
 *   - @b O/S:   Windows, Linux & OS X*
 *   - @b CPU:   All
 */
void OS_MutexDestroy(volatile OS_MUTEX_TYPE *lock);

/*! @ingroup OS_APIS_MUTEX
 * Aquire a mutex, blocks until the mutex becomes available (according to the mutex's semantics).
 *
 * @param[in]  lock               The mutex to acquire.
 *
 * @par Availability:
 *   - @b O/S:   Windows, Linux & OS X*
 *   - @b CPU:   All
 */
void OS_MutexLock(volatile OS_MUTEX_TYPE *lock);

/*! @ingroup OS_APIS_MUTEX
 * Tries to aquire a mutex:\n
 * - If the mutex is available, acquire it and return true.\n
 * - Otherwise, return false.
 *
 * @param[in]  lock               The mutex to acquire.
 *
 * @retval     TRUE               If the mutex was acquired.
 *
 * @par Availability:
 *   - @b O/S:   Windows, Linux & OS X*
 *   - @b CPU:   All
 */
BOOL_T OS_MutexTryLock(volatile OS_MUTEX_TYPE *lock);

/*! @ingroup OS_APIS_MUTEX
 * Releases a mutex.
 *
 * @param[in]  lock               The mutex to release.
 *
 * @par Availability:
 *   - @b O/S:   Windows, Linux & OS X*
 *   - @b CPU:   All
 */
void OS_MutexUnlock(volatile OS_MUTEX_TYPE *lock);

#endif // OS_APIS_MUTEX_H_INCLUDED_
