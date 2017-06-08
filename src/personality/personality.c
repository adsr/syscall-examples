#define SYSCALL "personality"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
PERSONALITY(2)             Linux Programmer's Manual            PERSONALITY(2)

NAME
       personality - set the process execution domain

SYNOPSIS
       #include <sys/personality.h>

       int personality(unsigned long persona);

DESCRIPTION
       Linux  supports different execution domains, or personalities, for each
       process.  Among other things, execution domains tell Linux how  to  map
       signal numbers into signal actions.  The execution domain system allows
       Linux to provide limited support  for  binaries  compiled  under  other
       UNIX-like operating systems.

       If persona is not 0xffffffff, then personality() sets the caller's exe‐
       cution domain to the value specified by persona.  Specifying persona as
       0xffffffff  provides  a  way  of retrieving the current persona without
       changing it.

       A list of the available execution domains can be found in  <sys/person‐
       ality.h>.

RETURN VALUE
       On  success,  the  previous  persona  is  returned.   On  error,  -1 is
       returned, and errno is set appropriately.

ERRORS
       EINVAL The kernel was unable to change the personality.

VERSIONS
       This system call first appeared in Linux 1.1.20;  library  support  was
       added in glibc 2.3.

CONFORMING TO
       personality()  is  Linux-specific  and  should  not be used in programs
       intended to be portable.

SEE ALSO
       setarch(8)

COLOPHON
       This page is part of release 4.04 of the Linux  man-pages  project.   A
       description  of  the project, information about reporting bugs, and the
       latest    version    of    this    page,    can     be     found     at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-12-28                    PERSONALITY(2)
*/
