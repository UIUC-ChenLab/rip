// <ORIGINAL-AUTHOR>: Greg Lueck
// <COMPONENT>: os-apis
// <FILE-TYPE>: component public header

#ifndef OS_APIS_BARESYSCALL_H__
#define OS_APIS_BARESYSCALL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"
#include <stdarg.h>

/*!
 * Set of raw return values from a system call.
 */
typedef struct /*<POD>*/
{
#if defined(TARGET_IA32)
    ADDRINT _eax;
# if defined(TARGET_MAC)
    ADDRINT _edx;
    ADDRINT _cf;      // cary flag after syscall
    ADDRINT _stack;   // value pointed at by SP after syscall
# endif

#elif defined(TARGET_IA32E) || defined(TARGET_MIC)
    ADDRINT _rax;
# if defined(TARGET_MAC)
    ADDRINT _rdx;
    ADDRINT _cf;
# endif
#endif

#ifdef TARGET_LINUX
    BOOL_T _success;
#endif
} BARESYSCALL_RETURN;


/*!
 * Perform a system call.
 *
 *  @param[in] sysno        The system call number.
 *  @param[in] argCount     The number of system call parameters.
 *  @param[in] ...          A variable number of system call parameters.
 *
 * @return  Returns a BARESYSCALL_RETURN object, which can be used to
 *          examine success and result values.
 */
BARESYSCALL_RETURN BARESYSCALL_Do(ADDRINT sysno, unsigned argCount, ...);

BARESYSCALL_RETURN BARESYSCALL_DoClone(ADDRINT flags, void* childStack, ADDRINT* parentTid,
        void* childTls, ADDRINT* childTid);

/*!
 * @return  TRUE if the last system call returned a "success" return.
 *           FALSE if the last system call returned an "error" return.
 */
BOOL_T BARESYSCALL_IsSuccess(BARESYSCALL_RETURN ret);

/*!
 * @return  The last system call's return value.  If IsSuccess() is FALSE,
 *           this is an O/S dependent error code.
 *          IMPORTANT! on FreeBSD "pipe" this returns only the value of
 *          rax (or eax). to get the second value use RAW_RETURN. same
 *          goes for any syscall with multiple return registers.
 */
ADDRINT BARESYSCALL_ReturnValue(BARESYSCALL_RETURN ret);

#ifdef TARGET_MAC

/*!
 * @return  The last system call's second return value.  If IsSuccess() is FALSE,
 *           this is an O/S dependent error code.
 */
ADDRINT BARESYSCALL_ReturnValue2(BARESYSCALL_RETURN ret);

#endif

#ifdef TARGET_LINUX
/*
 * This is the signal restorer which is called after a signal handler
 * had returned.
 * This is basically a system call to restore the original application's
 * stack.
 * This syscall never returns
 */
extern void OS_BARESYSCALL_RtSigReturn();
# ifdef TARGET_IA32
extern void OS_BARESYSCALL_SigReturn();
# endif
#endif

#ifdef __cplusplus
}
#endif

#endif // file guard
