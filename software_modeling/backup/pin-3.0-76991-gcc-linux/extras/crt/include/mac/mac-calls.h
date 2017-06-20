// <ORIGINAL-AUTHOR>: Benjamin Kemper
// <COMPONENT>: os-apis
// <FILE-TYPE>: component public header

#ifndef OS_APIS_MAC_CALLS_H__
#define OS_APIS_MAC_CALLS_H__

#include "os-apis.h"
#include <mach/mach.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(TARGET_IA32E)
 #define SYSCALL_SHIFT 24
 #define SYSCALL_CLASS_SHIFT 24
 #define SYSCALL_CLASS_MASK  (0xFF << SYSCALL_CLASS_SHIFT)
 #define SYSCALL_NUMBER_MASK (~SYSCALL_CLASS_MASK)
 #define SYSCALL_CONSTRUCT_MACH(syscall_number) \
          ((SYSCALL_CLASS_MACH << SYSCALL_CLASS_SHIFT) | \
           (SYSCALL_NUMBER_MASK & (syscall_number)))
#elif defined(TARGET_IA32)
 #define SYSCALL_SHIFT 16
 #define SYSCALL_CLASS_SHIFT    (16)
 #define SYSCALL_CLASS_MASK     (0xFF << SYSCALL_CLASS_SHIFT)
 #define SYSCALL_NUMBER_MASK    (0xFFFF)
 #define SYSCALL_CONSTRUCT_MACH(syscall_number) \
          (-syscall_number)
#else
# error "Unknown platform"
#endif

#define SYSCALL_CLASS_NONE  0   /* Invalid */
#define SYSCALL_CLASS_MACH  1   /* Mach */
#define SYSCALL_CLASS_UNIX  2   /* Unix/BSD */
#define SYSCALL_CLASS_MDEP  3   /* Machine-dependent */
#define SYSCALL_CLASS_DIAG  4   /* Diagnostics */
#define SYSCALL_CLASS_IPC   5   /* Mach IPC */

/* Macros to simpllfy constructing syscall numbers. */
#define SYSCALL_CONSTRUCT_UNIX(syscall_number) \
         ((SYSCALL_CLASS_UNIX << SYSCALL_CLASS_SHIFT) | \
          (SYSCALL_NUMBER_MASK & (syscall_number)))
#define SYSCALL_CONSTRUCT_MDEP(syscall_number) \
         ((SYSCALL_CLASS_MDEP << SYSCALL_CLASS_SHIFT) | \
          (SYSCALL_NUMBER_MASK & (syscall_number)))
#define SYSCALL_CONSTRUCT_DIAG(syscall_number) \
         ((SYSCALL_CLASS_DIAG << SYSCALL_CLASS_SHIFT) | \
          (SYSCALL_NUMBER_MASK & (syscall_number)))

#ifdef TARGET_IA32
# define SYSCALL_CONSTRUCT_UNIX_INT80(syscall_number) (syscall_number|0x04000000)
#else
# define SYSCALL_CONSTRUCT_UNIX_INT80(syscall_number) SYSCALL_CONSTRUCT_UNIX(syscall_number)
#endif


#define msgh_request_port   msgh_remote_port
#define msgh_reply_port     msgh_local_port

extern NDR_record_t MY_NDR_record;

int MacSysCtl(int *name, u_int namelen, void *oldp, size_t *oldlenp,
    void *newp, size_t newlen);

mach_port_t OS_mach_alloc_reply_port();
kern_return_t OS_mach_port_deallocate ( ipc_space_t task, mach_port_name_t name);
mach_msg_return_t OS_mach_msg(mach_msg_header_t *msg, mach_msg_option_t option, mach_msg_size_t send_size, mach_msg_size_t rcv_size,
        mach_port_t rcv_name, mach_msg_timeout_t timeout, mach_port_t notify);
mach_msg_return_t OS_mach_msg_send(mach_msg_header_t *msg);
mach_msg_return_t OS_mach_msg_receive(mach_msg_header_t *msg);
int OS_proc_info(int callnum, int pid, int flavor, uint64_t arg, void * buffer, int buffersize);
int OS_proc_pidinfo(int pid, int flavor, uint64_t arg,  void *buffer, int buffersize);

#ifdef __cplusplus
}
#endif

#endif // OS_APIS_MAC_CALLS_H__

