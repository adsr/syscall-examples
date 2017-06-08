#define SYSCALL "pause"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
PAUSE(2)                   Linux Programmer's Manual                  PAUSE(2)

NAME
       pause - wait for signal

SYNOPSIS
       #include <unistd.h>

       int pause(void);

DESCRIPTION
       pause()  causes the calling process (or thread) to sleep until a signal
       is delivered that either terminates the process or causes  the  invoca‐
       tion of a signal-catching function.

RETURN VALUE
       pause()  returns  only when a signal was caught and the signal-catching
       function returned.  In this case, pause() returns -1, and errno is  set
       to EINTR.

ERRORS
       EINTR  a signal was caught and the signal-catching function returned.

CONFORMING TO
       POSIX.1-2001, POSIX.1-2008, SVr4, 4.3BSD.

SEE ALSO
       kill(2), select(2), signal(2), sigsuspend(2)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-08-08                          PAUSE(2)
*/
