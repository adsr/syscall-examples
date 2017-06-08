#define SYSCALL "lookup_dcookie"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
LOOKUP_DCOOKIE(2)          Linux Programmer's Manual         LOOKUP_DCOOKIE(2)

NAME
       lookup_dcookie - return a directory entry's path

SYNOPSIS
       int lookup_dcookie(u64 cookie, char *buffer, size_t len);

DESCRIPTION
       Look  up  the  full  path of the directory entry specified by the value
       cookie.  The cookie is an opaque identifier uniquely identifying a par‐
       ticular  directory  entry.  The buffer given is filled in with the full
       path of the directory entry.

       For lookup_dcookie() to return successfully, the kernel must still hold
       a cookie reference to the directory entry.

RETURN VALUE
       On  success,  lookup_dcookie()  returns  the  length of the path string
       copied into the buffer.  On error, -1 is returned,  and  errno  is  set
       appropriately.

ERRORS
       EFAULT The buffer was not valid.

       EINVAL The  kernel has no registered cookie/directory entry mappings at
              the time of lookup, or the cookie does  not  refer  to  a  valid
              directory entry.

       ENAMETOOLONG
              The name could not fit in the buffer.

       ENOMEM The  kernel  could  not allocate memory for the temporary buffer
              holding the path.

       EPERM  The process does not have the capability CAP_SYS_ADMIN  required
              to look up cookie values.

       ERANGE The  buffer  was not large enough to hold the path of the direc‐
              tory entry.

VERSIONS
       Available since Linux 2.5.43.  The ENAMETOOLONG error return was  added
       in 2.5.70.

CONFORMING TO
       lookup_dcookie() is Linux-specific.

NOTES
       lookup_dcookie()  is a special-purpose system call, currently used only
       by the oprofile profiler.  It relies on a  kernel  driver  to  register
       cookies for directory entries.

       The  path  returned  may  be suffixed by the string " (deleted)" if the
       directory entry has been removed.

COLOPHON
       This page is part of release 4.04 of the Linux  man-pages  project.   A
       description  of  the project, information about reporting bugs, and the
       latest    version    of    this    page,    can     be     found     at
       http://www.kernel.org/doc/man-pages/.

Linux                             2004-06-17                 LOOKUP_DCOOKIE(2)
*/
