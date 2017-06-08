#define SYSCALL "nice"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
NICE(2)                    Linux Programmer's Manual                   NICE(2)

NAME
       nice - change process priority

SYNOPSIS
       #include <unistd.h>

       int nice(int inc);

   Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

       nice(): _BSD_SOURCE || _SVID_SOURCE || _XOPEN_SOURCE

DESCRIPTION
       nice()  adds  inc to the nice value for the calling process.  (A higher
       nice value means a low priority.)  Only the  superuser  may  specify  a
       negative increment, or priority increase.  The range for nice values is
       described in getpriority(2).

RETURN VALUE
       On success, the new nice value is returned (but see NOTES  below).   On
       error, -1 is returned, and errno is set appropriately.

ERRORS
       EPERM  The  calling  process attempted to increase its priority by sup‐
              plying a negative inc but has  insufficient  privileges.   Under
              Linux,  the  CAP_SYS_NICE  capability is required.  (But see the
              discussion of the RLIMIT_NICE resource limit in setrlimit(2).)

CONFORMING TO
       POSIX.1-2001, POSIX.1-2008,  SVr4,  4.3BSD.   However,  the  Linux  and
       (g)libc  (earlier  than  glibc  2.2.4) return value is nonstandard, see
       below.  SVr4 documents an additional EINVAL error code.

NOTES
       SUSv2 and POSIX.1 specify that nice() should return the new nice value.
       However, the Linux system call and the nice() library function provided
       in older versions of (g)libc (earlier than glibc  2.2.4)  return  0  on
       success.  The new nice value can be found using getpriority(2).

       Since  glibc  2.2.4,  nice()  is implemented as a library function that
       calls getpriority(2) to obtain the new nice value to be returned to the
       caller.   With  this implementation, a successful call can legitimately
       return -1.  To reliably detect an error, set  errno  to  0  before  the
       call, and check its value when nice() returns -1.

SEE ALSO
       nice(1),  renice(1), fork(2), getpriority(2), setpriority(2), capabili‐
       ties(7), sched(7)

COLOPHON
       This page is part of release 4.04 of the Linux  man-pages  project.   A
       description  of  the project, information about reporting bugs, and the
       latest    version    of    this    page,    can     be     found     at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-08-08                           NICE(2)
*/
