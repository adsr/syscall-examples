#define SYSCALL "getsockname"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
GETSOCKNAME(2)             Linux Programmer's Manual            GETSOCKNAME(2)

NAME
       getsockname - get socket name

SYNOPSIS
       #include <sys/socket.h>

       int getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

DESCRIPTION
       getsockname() returns the current address to which the socket sockfd is
       bound, in the buffer pointed to by addr.  The addrlen  argument  should
       be initialized to indicate the amount of space (in bytes) pointed to by
       addr.  On return it contains the actual size of the socket address.

       The returned address is truncated if the buffer provided is too  small;
       in  this case, addrlen will return a value greater than was supplied to
       the call.

RETURN VALUE
       On success, zero is returned.  On error, -1 is returned, and  errno  is
       set appropriately.

ERRORS
       EBADF  The argument sockfd is not a valid descriptor.

       EFAULT The  addr  argument  points to memory not in a valid part of the
              process address space.

       EINVAL addrlen is invalid (e.g., is negative).

       ENOBUFS
              Insufficient resources were available in the system  to  perform
              the operation.

       ENOTSOCK
              The file descriptor sockfd does not refer to a socket.

CONFORMING TO
       POSIX.1-2001,  POSIX.1-2008, SVr4, 4.4BSD (getsockname() first appeared
       in 4.2BSD).

NOTES
       The third argument of getsockname() is in reality an int * (and this is
       what  4.x BSD and libc4 and libc5 have).  Some POSIX confusion resulted
       in the present socklen_t, also used by glibc.  See also accept(2).

SEE ALSO
       bind(2), socket(2), getifaddrs(3), ip(7), socket(7), unix(7)

COLOPHON
       This page is part of release 4.04 of the Linux  man-pages  project.   A
       description  of  the project, information about reporting bugs, and the
       latest    version    of    this    page,    can     be     found     at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-12-28                    GETSOCKNAME(2)
*/
