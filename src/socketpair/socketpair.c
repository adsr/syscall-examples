#define SYSCALL "socketpair"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
SOCKETPAIR(2)              Linux Programmer's Manual             SOCKETPAIR(2)

NAME
       socketpair - create a pair of connected sockets

SYNOPSIS
       #include <sys/types.h>          /* See NOTES *|
       #include <sys/socket.h>

       int socketpair(int domain, int type, int protocol, int sv[2]);

DESCRIPTION
       The  socketpair()  call creates an unnamed pair of connected sockets in
       the specified domain, of the specified type, and using  the  optionally
       specified  protocol.   For  further  details  of  these  arguments, see
       socket(2).

       The descriptors used in referencing the new  sockets  are  returned  in
       sv[0] and sv[1].  The two sockets are indistinguishable.

RETURN VALUE
       On  success,  zero is returned.  On error, -1 is returned, and errno is
       set appropriately.

ERRORS
       EAFNOSUPPORT
              The specified address family is not supported on this machine.

       EFAULT The address sv does not specify a  valid  part  of  the  process
              address space.

       EMFILE The per-process limit on the number of open file descriptors has
              been reached.

       ENFILE The system-wide limit on the total number of open files has been
              reached.

       EOPNOTSUPP
              The  specified  protocol  does  not  support  creation of socket
              pairs.

       EPROTONOSUPPORT
              The specified protocol is not supported on this machine.

CONFORMING TO
       POSIX.1-2001, POSIX.1-2008, 4.4BSD.   socketpair()  first  appeared  in
       4.2BSD.   It  is  generally portable to/from non-BSD systems supporting
       clones of the BSD socket layer (including System V variants).

NOTES
       On Linux, the only supported domain for this call is AF_UNIX  (or  syn‐
       onymously,  AF_LOCAL).   (Most  implementations  have the same restric‐
       tion.)

       Since  Linux  2.6.27,  socketpair()  supports  the  SOCK_NONBLOCK   and
       SOCK_CLOEXEC flags in the type argument, as described in socket(2).

       POSIX.1  does  not  require  the  inclusion  of <sys/types.h>, and this
       header file is not required on Linux.  However, some  historical  (BSD)
       implementations  required  this  header file, and portable applications
       are probably wise to include it.

SEE ALSO
       pipe(2), read(2), socket(2), write(2), socket(7), unix(7)

COLOPHON
       This page is part of release 4.04 of the Linux  man-pages  project.   A
       description  of  the project, information about reporting bugs, and the
       latest    version    of    this    page,    can     be     found     at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-12-28                     SOCKETPAIR(2)
*/
