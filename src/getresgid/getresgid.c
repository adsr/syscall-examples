#define SYSCALL "getresgid"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
GETRESUID(2)               Linux Programmer's Manual              GETRESUID(2)

NAME
       getresuid, getresgid - get real, effective and saved user/group IDs

SYNOPSIS
       #define _GNU_SOURCE         /* See feature_test_macros(7) *|
       #include <unistd.h>

       int getresuid(uid_t *ruid, uid_t *euid, uid_t *suid);
       int getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid);

DESCRIPTION
       getresuid() returns the real UID, the effective UID, and the saved set-
       user-ID of the calling process, in the arguments ruid, euid, and  suid,
       respectively.    getresgid()   performs  the  analogous  task  for  the
       process's group IDs.

RETURN VALUE
       On success, zero is returned.  On error, -1 is returned, and  errno  is
       set appropriately.

ERRORS
       EFAULT One  of  the  arguments specified an address outside the calling
              program's address space.

VERSIONS
       These system calls appeared on Linux starting with kernel 2.1.44.

       The prototypes  are  given  by  glibc  since  version  2.3.2,  provided
       _GNU_SOURCE is defined.

CONFORMING TO
       These  calls are nonstandard; they also appear on HP-UX and some of the
       BSDs.

NOTES
       The original Linux getresuid() and getresgid() system  calls  supported
       only  16-bit  user and group IDs.  Subsequently, Linux 2.4 added getre‐
       suid32() and getresgid32(), supporting 32-bit IDs.   The  glibc  getre‐
       suid()  and  getresgid()  wrapper functions transparently deal with the
       variations across kernel versions.

SEE ALSO
       getuid(2), setresuid(2), setreuid(2), setuid(2), credentials(7)

COLOPHON
       This page is part of release 4.04 of the Linux  man-pages  project.   A
       description  of  the project, information about reporting bugs, and the
       latest    version    of    this    page,    can     be     found     at
       http://www.kernel.org/doc/man-pages/.

Linux                             2010-11-22                      GETRESUID(2)
*/
