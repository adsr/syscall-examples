#define SYSCALL "stime"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
STIME(2)                   Linux Programmer's Manual                  STIME(2)

NAME
       stime - set time

SYNOPSIS
       #include <time.h>

       int stime(const time_t *t);

   Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

       stime(): _SVID_SOURCE

DESCRIPTION
       stime() sets the system's idea of the time and date.  The time, pointed
       to by t, is measured in seconds since the  Epoch,  1970-01-01  00:00:00
       +0000 (UTC).  stime() may be executed only by the superuser.

RETURN VALUE
       On  success,  zero is returned.  On error, -1 is returned, and errno is
       set appropriately.

ERRORS
       EFAULT Error in getting information from user space.

       EPERM  The calling process has insufficient  privilege.   Under  Linux,
              the CAP_SYS_TIME privilege is required.

CONFORMING TO
       SVr4.

SEE ALSO
       date(1), settimeofday(2), capabilities(7)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2014-05-10                          STIME(2)
*/
