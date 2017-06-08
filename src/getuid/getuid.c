#define SYSCALL "getuid"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
GETUID(2)                  Linux Programmer's Manual                 GETUID(2)

NAME
       getuid, geteuid - get user identity

SYNOPSIS
       #include <unistd.h>
       #include <sys/types.h>

       uid_t getuid(void);
       uid_t geteuid(void);

DESCRIPTION
       getuid() returns the real user ID of the calling process.

       geteuid() returns the effective user ID of the calling process.

ERRORS
       These functions are always successful.

CONFORMING TO
       POSIX.1-2001, POSIX.1-2008, 4.3BSD.

NOTES
   History
       In  UNIX V6  the  getuid()  call  returned  (euid << 8) + uid.  UNIX V7
       introduced separate calls getuid() and geteuid().

       The original Linux getuid() and geteuid() system calls  supported  only
       16-bit   user  IDs.   Subsequently,  Linux  2.4  added  getuid32()  and
       geteuid32(), supporting 32-bit IDs.  The glibc getuid()  and  geteuid()
       wrapper  functions transparently deal with the variations across kernel
       versions.

SEE ALSO
       getresuid(2), setreuid(2), setuid(2), credentials(7)

COLOPHON
       This page is part of release 4.04 of the Linux  man-pages  project.   A
       description  of  the project, information about reporting bugs, and the
       latest    version    of    this    page,    can     be     found     at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-08-08                         GETUID(2)
*/
