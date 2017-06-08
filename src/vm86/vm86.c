#define SYSCALL "vm86"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
VM86(2)                    Linux Programmer's Manual                   VM86(2)

NAME
       vm86old, vm86 - enter virtual 8086 mode

SYNOPSIS
       #include <sys/vm86.h>

       int vm86old(struct vm86_struct *info);

       int vm86(unsigned long fn, struct vm86plus_struct *v86);

DESCRIPTION
       The system call vm86() was introduced in Linux 0.97p2.  In Linux 2.1.15
       and 2.0.28, it was renamed to vm86old(), and a new  vm86()  was  intro‐
       duced.   The  definition of struct vm86_struct was changed in 1.1.8 and
       1.1.9.

       These calls cause the process to enter VM86 mode (virtual-8086 in Intel
       literature), and are used by dosemu.

       VM86 mode is an emulation of real mode within a protected mode task.

RETURN VALUE
       On  success,  zero is returned.  On error, -1 is returned, and errno is
       set appropriately.

ERRORS
       EFAULT This return value is specific to i386 and  indicates  a  problem
              with getting user-space data.

       ENOSYS This  return  value indicates the call is not implemented on the
              present architecture.

       EPERM  Saved kernel stack exists.  (This is a kernel sanity check;  the
              saved stack should exist only within vm86 mode itself.)

CONFORMING TO
       This  call  is specific to Linux on 32-bit Intel processors, and should
       not be used in programs intended to be portable.

COLOPHON
       This page is part of release 4.04 of the Linux  man-pages  project.   A
       description  of  the project, information about reporting bugs, and the
       latest    version    of    this    page,    can     be     found     at
       http://www.kernel.org/doc/man-pages/.

Linux                             2009-02-20                           VM86(2)
*/
