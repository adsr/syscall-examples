#define SYSCALL "socketcall"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
SOCKETCALL(2)              Linux Programmer's Manual             SOCKETCALL(2)

NAME
       socketcall - socket system calls

SYNOPSIS
       int socketcall(int call, unsigned long *args);

DESCRIPTION
       socketcall()  is  a  common  kernel  entry  point for the socket system
       calls.  call determines which socket function to invoke.   args  points
       to a block containing the actual arguments, which are passed through to
       the appropriate call.

       User programs should call the  appropriate  functions  by  their  usual
       names.   Only  standard library implementors and kernel hackers need to
       know about socketcall().

CONFORMING TO
       This call is specific to Linux, and should  not  be  used  in  programs
       intended to be portable.

NOTES
       On a some architectures—for example, x86-64 and ARM—there is no socket‐
       call() system call; instead socket(2), accept(2), bind(2),  and  so  on
       really are implemented as separate system calls.

       On  x86-32,  socketcall() was historically the only entry point for the
       sockets API.  However, starting in Linux 4.3, direct system  calls  are
       provided  on x86-32 for the sockets API.  This facilitates the creation
       of seccomp(2) filters that filter sockets system calls (for  new  user-
       space  binaries that are compiled to use the new entry points) and also
       provides a (very) small performance improvement.

SEE ALSO
       accept(2), bind(2), connect(2),  getpeername(2),  getsockname(2),  get‐
       sockopt(2),   listen(2),  recv(2),  recvfrom(2),  recvmsg(2),  send(2),
       sendmsg(2), sendto(2), setsockopt(2), shutdown(2),  socket(2),  socket‐
       pair(2)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-12-28                     SOCKETCALL(2)
*/
