// <ORIGINAL-AUTHOR>: Robert Muth
// <COMPONENT>: os-apis
// <FILE-TYPE>: component private header

/*! @file
 * this headerfile contains defines the types that are the foundation of
 * other code
 */
/*!
 * @defgroup OS_APIS_TYPES Data types
 * @brief Contains data-type definitions
 */

#ifndef OS_TYPES_H
#define OS_TYPES_H

#if defined(__GNUC__)
#   include <stdint.h>
#endif

/*! @ingroup OS_APIS_TYPES
 * Data type for boolean
 */
#ifdef  __cplusplus
typedef bool BOOL_T;
#else
typedef unsigned char BOOL_T;
#endif

#if !defined(TRUE)
#   define TRUE 1
#endif
#if !defined(FALSE)
#   define FALSE 0
#endif

#if !defined(VOID)
typedef void VOID;
#endif

#if !defined(NULL)
#    define NULL ((void*)0)
#endif

typedef char            CHAR;
typedef unsigned int    UINT;
typedef int             INT;
typedef double          FLT64;
typedef float           FLT32;
/*! @ingroup OS_APIS_TYPES
 * Generic type for three-state logic.
 */
enum TRI
{
    TRI_YES,
    TRI_NO,
    TRI_MAYBE
};

#if defined(_MSC_VER)
typedef unsigned __int8 UINT8 ;
typedef unsigned __int16 UINT16;
typedef unsigned __int32 UINT32;
typedef unsigned __int64 UINT64;
typedef signed __int8 INT8 ;
typedef signed __int16 INT16;
typedef signed __int32 INT32;
typedef signed __int64 INT64;
#ifndef TARGET_WINDOWS
typedef __int8 INT8;
typedef __int16 INT16;
typedef __int64 INT64;
#endif
typedef __int32 INT32;

#else
typedef uint8_t  UINT8;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef uint64_t UINT64;
typedef int8_t  INT8;
typedef int16_t INT16;
typedef int32_t INT32;
typedef int64_t INT64;
# endif


/*
 * Unsigned integer of the same size as a pointer on the TARGET architecture.
 * This quantity can be converted to and from an OADDR/IADDR
 *
 * There is an option of overflow and underflow when using ADDRDELTA.
 * For example, let's look at a 32 bit address.
 * 32 bit address is 32 bit unsigned int number.
 * This means that the maximum delta between two addresses is (2^32 - 1),
 * which means that the ADDRDELTA which is signed may overflow.
 */
#if defined(TARGET_IA32)
typedef UINT32 ADDRINT;
// typedef int INT32;
typedef INT32 ADDRDELTA;


#elif (defined(TARGET_IA32E) || defined(TARGET_MIC))
typedef UINT64 ADDRINT;
typedef INT64 ADDRDELTA;

#elif defined(TARGET_DOXYGEN)
typedef xxx ADDRINT;
typedef xxx ADDRDELTA;

#else
#error "Unsupported target architecture"
#endif

typedef ADDRINT    USIZE;

#if defined(HOST_IA32)
typedef UINT32 VOIDINT;
#elif defined(HOST_IA32E) || defined(HOST_MIC)
typedef UINT64 VOIDINT;
#else
typedef ADDRINT VOIDINT;
#endif

typedef UINT64 REG_CLASS_BITS;
typedef UINT32 REG_SUBCLASS_BITS;

/*
 * Generic macro definitions
 */

#if defined(_MSC_VER)
# define ALIGNMENT_OF(t) __alignof(t)
#else
# define ALIGNMENT_OF(t) __alignof__(t)
#endif

/*! @ingroup OS_APIS_TYPES
 * Generic data type to refer to a kernel file object.
 * This is actually an HANDLE in Windows, and a file descriptor
 * (int) on Unix systems.
 */
typedef ADDRINT NATIVE_FD;

/*! @ingroup OS_APIS_TYPES
 * Data type that can hold a process ID.
 * On OS-APIs all processes can be refered to by their PIDs.
 */
typedef ADDRINT NATIVE_PID;

/*! @ingroup OS_APIS_TYPES
 * Data type that can hold a thread ID.
 * On OS-APIs all threads can be refered to by their TIDs.
 */
typedef ADDRINT NATIVE_TID;

typedef ADDRINT PIN_TID;

#define INVALID_PIN_TID ((PIN_TID)-1LL)
#define INVALID_NATIVE_FD ((NATIVE_FD)-1LL)
#define INVALID_NATIVE_TID ((NATIVE_TID)-1LL)
#define INVALID_NATIVE_PID ((NATIVE_PID)-1LL)
#define NATIVE_PID_CURRENT ((NATIVE_PID)0)
#define NATIVE_TID_CURRENT ((NATIVE_TID)0)

#endif
