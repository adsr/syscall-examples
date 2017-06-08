#define SYSCALL "vhangup"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
VHANGUP(2)                 Linux Programmer's Manual                VHANGUP(2)

NAME
       vhangup - virtually hangup the current terminal

SYNOPSIS
       #include <unistd.h>

       int vhangup(void);

   Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

       vhangup(): _BSD_SOURCE || (_XOPEN_SOURCE && _XOPEN_SOURCE < 500)

DESCRIPTION
       vhangup()  simulates  a  hangup  on  the  current  terminal.  This call
       arranges for other users to have a “clean” terminal at login time.

RETURN VALUE
       On success, zero is returned.  On error, -1 is returned, and  errno  is
       set appropriately.

ERRORS
       EPERM  The   calling   process   has  insufficient  privilege  to  call
              vhangup(); the CAP_SYS_TTY_CONFIG capability is required.

CONFORMING TO
       This call is  Linux-specific,  and  should  not  be  used  in  programs
       intended to be portable.

SEE ALSO
       capabilities(7), init(1)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2007-07-26                        VHANGUP(2)
*/
