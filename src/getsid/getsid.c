#define SYSCALL "getsid"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
GETSID(2)                  Linux Programmer's Manual                 GETSID(2)

NAME
       getsid - get session ID

SYNOPSIS
       #include <unistd.h>

       pid_t getsid(pid_t pid);

   Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

       getsid():
           _XOPEN_SOURCE >= 500 || _XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED
           || /* Since glibc 2.12: *| _POSIX_C_SOURCE >= 200809L

DESCRIPTION
       getsid(0)  returns  the  session  ID of the calling process.  getsid(p)
       returns the session ID of the process with process ID p.  (The  session
       ID of a process is the process group ID of the session leader.)

RETURN VALUE
       On  success,  a  session  ID is returned.  On error, (pid_t) -1 will be
       returned, and errno is set appropriately.

ERRORS
       EPERM  A process with process ID p exists, but it is not  in  the  same
              session as the calling process, and the implementation considers
              this an error.

       ESRCH  No process with process ID p was found.

VERSIONS
       This system call is available on Linux since version 2.0.

CONFORMING TO
       POSIX.1-2001, POSIX.1-2008, SVr4.

NOTES
       Linux does not return EPERM.

SEE ALSO
       getpgid(2), setsid(2), credentials(7)

COLOPHON
       This page is part of release 4.04 of the Linux  man-pages  project.   A
       description  of  the project, information about reporting bugs, and the
       latest    version    of    this    page,    can     be     found     at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-08-08                         GETSID(2)
*/
