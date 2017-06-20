#ifndef _UAPI_MAC_FCNTL_H
#define _UAPI_MAC_FCNTL_H

/*
 * File status flags: these are used by open(2), fcntl(2).
 * They are also used (indirectly) in the kernel file structure f_flags,
 * which is a superset of the open/fcntl flags.  Open flags and f_flags
 * are inter-convertible using OFLAGS(fflags) and FFLAGS(oflags).
 * Open/fcntl flags begin with O_; kernel-internal flags begin with F.
 */
/* open-only flags */
#define O_RDONLY        0x0000          /* open for reading only */
#define O_WRONLY        0x0001          /* open for writing only */
#define O_RDWR          0x0002          /* open for reading and writing */
#define O_ACCMODE       0x0003          /* mask for above modes */

/*
 * Kernel encoding of open mode; separate read and write bits that are
 * independently testable: 1 greater than the above.
 *
 * XXX
 * FREAD and FWRITE are excluded from the #ifdef KERNEL so that TIOCFLUSH,
 * which was documented to use FREAD/FWRITE, continues to work.
 */
#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
#define FREAD           0x0001
#define FWRITE          0x0002
#endif
#define O_NONBLOCK      0x0004          /* no delay */
#define O_APPEND        0x0008          /* set append mode */
#ifndef O_SYNC          /* allow simultaneous inclusion of <aio.h> */
#define O_SYNC          0x0080          /* synch I/O file integrity */
#endif
#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
#define O_SHLOCK        0x0010          /* open with shared file lock */
#define O_EXLOCK        0x0020          /* open with exclusive file lock */
#define O_ASYNC         0x0040          /* signal pgrp when data ready */
#define O_FSYNC         O_SYNC          /* source compatibility: do not use */
#define O_NOFOLLOW  0x0100      /* don't follow symlinks */
#endif /* (_POSIX_C_SOURCE && !_DARWIN_C_SOURCE) */
#define O_CREAT         0x0200          /* create if nonexistant */
#define O_TRUNC         0x0400          /* truncate to zero length */
#define O_EXCL          0x0800          /* error if already exists */
#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
#define O_EVTONLY       0x8000          /* descriptor requested for event notifications only */
#endif


#define O_NOCTTY        0x20000         /* don't assign controlling terminal */


#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
#define O_DIRECTORY     0x100000
#define O_SYMLINK       0x200000        /* allow open of a symlink */
#endif

#ifndef O_DSYNC         /* allow simultaneous inclusion of <aio.h> */
#define         O_DSYNC 0x400000        /* synch I/O data integrity */
#endif

#if __DARWIN_C_LEVEL >= 200809L
#define O_CLOEXEC       0x1000000       /* implicitly set FD_CLOEXEC */
#endif

#ifndef F_DUPFD
#define F_DUPFD     0   /* dup */
#define F_GETFD     1   /* get close_on_exec */
#define F_SETFD     2   /* set/clear close_on_exec */
#define F_GETFL     3   /* get file->f_flags */
#define F_SETFL     4   /* set file->f_flags */
#define F_GETLK     5
#define F_SETLK     6
#define F_SETLKW    7

#define F_SETOWN    8   /*  for sockets. */
#define F_GETOWN    9   /*  for sockets. */
#define F_SETSIG    10  /*  for sockets. */
#define F_GETSIG    11  /*  for sockets. */

/* for F_[GET|SET]FL */
#define FD_CLOEXEC  1   /* actually anything with low bit set goes */
#endif // defined(F_DUPFD)

/*
 * [XSI] The symbolic names for file modes for use as values of mode_t
 * shall be defined as described in <sys/stat.h>
 */
#ifndef S_IFMT
/* File type */
#define S_IFMT          0170000         /* [XSI] type of file mask */
#define S_IFIFO         0010000         /* [XSI] named pipe (fifo) */
#define S_IFCHR         0020000         /* [XSI] character special */
#define S_IFDIR         0040000         /* [XSI] directory */
#define S_IFBLK         0060000         /* [XSI] block special */
#define S_IFREG         0100000         /* [XSI] regular */
#define S_IFLNK         0120000         /* [XSI] symbolic link */
#define S_IFSOCK        0140000         /* [XSI] socket */
#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
#define S_IFWHT         0160000         /* OBSOLETE: whiteout */
#endif


#ifndef S_IRWXU
/* File mode */
/* Read, write, execute/search by owner */
#define S_IRWXU         0000700         /* [XSI] RWX mask for owner */
#define S_IRUSR         0000400         /* [XSI] R for owner */
#define S_IWUSR         0000200         /* [XSI] W for owner */
#define S_IXUSR         0000100         /* [XSI] X for owner */
/* Read, write, execute/search by group */
#define S_IRWXG         0000070         /* [XSI] RWX mask for group */
#define S_IRGRP         0000040         /* [XSI] R for group */
#define S_IWGRP         0000020         /* [XSI] W for group */
#define S_IXGRP         0000010         /* [XSI] X for group */
/* Read, write, execute/search by others */
#define S_IRWXO         0000007         /* [XSI] RWX mask for other */
#define S_IROTH         0000004         /* [XSI] R for other */
#define S_IWOTH         0000002         /* [XSI] W for other */
#define S_IXOTH         0000001         /* [XSI] X for other */

#define S_ISUID         0004000         /* [XSI] set user id on execution */
#define S_ISGID         0002000         /* [XSI] set group id on execution */
#define S_ISVTX         0001000         /* [XSI] directory restrcted delete */

#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
#define S_ISTXT         S_ISVTX         /* sticky bit: not supported */
#define S_IREAD         S_IRUSR         /* backward compatability */
#define S_IWRITE        S_IWUSR         /* backward compatability */
#define S_IEXEC         S_IXUSR         /* backward compatability */
#endif
#endif
#endif  /* !S_IFMT */

#endif // _UAPI_MAC_FCNTL_H
