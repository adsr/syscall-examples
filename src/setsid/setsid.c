#define SYSCALL "setsid"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
SETSID(2)                  Linux Programmer's Manual                 SETSID(2)

NAME
       setsid - creates a session and sets the process group ID

SYNOPSIS
       #include <unistd.h>

       pid_t setsid(void);

DESCRIPTION
       setsid()  creates a new session if the calling process is not a process
       group leader.  The calling process is the leader  of  the  new  session
       (i.e., its session ID is made the same as its process ID).  The calling
       process also becomes the process group leader of a new process group in
       the session (i.e., its process group ID is made the same as its process
       ID).

       The calling process will be the only process in the new  process  group
       and in the new session.  The new session has no controlling terminal.

RETURN VALUE
       On  success,  the  (new) session ID of the calling process is returned.
       On error, (pid_t) -1 is returned, and errno  is  set  to  indicate  the
       error.

ERRORS
       EPERM  The  process group ID of any process equals the PID of the call‐
              ing process.  Thus, in particular, setsid() fails if the calling
              process is already a process group leader.

CONFORMING TO
       POSIX.1-2001, POSIX.1-2008, SVr4.

NOTES
       A child created via fork(2) inherits its parent's session ID.  The ses‐
       sion ID is preserved across an execve(2).

       A process group leader is a process whose process group ID  equals  its
       PID.  Disallowing a process group leader from calling setsid() prevents
       the possibility that a process group leader places itself in a new ses‐
       sion  while other processes in the process group remain in the original
       session; such a scenario would break the strict two-level hierarchy  of
       sessions  and  process  groups.  In order to be sure that setsid() will
       succeed, fork(2) and _exit(2), and have the child do setsid().

SEE ALSO
       setsid(1),  getsid(2),  setpgid(2),  setpgrp(2),  tcgetsid(3),  creden‐
       tials(7)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-08-08                         SETSID(2)
*/
