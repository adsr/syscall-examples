#define SYSCALL "getegid32"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
GETGID(2)                  Linux Programmer's Manual                 GETGID(2)

NAME
       getgid, getegid - get group identity

SYNOPSIS
       #include <unistd.h>
       #include <sys/types.h>

       gid_t getgid(void);
       gid_t getegid(void);

DESCRIPTION
       getgid() returns the real group ID of the calling process.

       getegid() returns the effective group ID of the calling process.

ERRORS
       These functions are always successful.

CONFORMING TO
       POSIX.1-2001, POSIX.1-2008, 4.3BSD.

NOTES
       The  original  Linux getgid() and getegid() system calls supported only
       16-bit group IDs.  Subsequently, Linux 2.4 added getgid32()  and  gete‐
       gid32(), supporting 32-bit IDs.  The glibc getgid() and getegid() wrap‐
       per functions transparently deal with the variations across kernel ver‐
       sions.

SEE ALSO
       getresgid(2), setgid(2), setregid(2), credentials(7)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-08-08                         GETGID(2)
*/
