#define SYSCALL "cacheflush"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
CACHEFLUSH(2)              Linux Programmer's Manual             CACHEFLUSH(2)

NAME
       cacheflush - flush contents of instruction and/or data cache

SYNOPSIS
       #include <asm/cachectl.h>

       int cacheflush(char *addr, int nbytes, int cache);

DESCRIPTION
       cacheflush()  flushes  the  contents  of the indicated cache(s) for the
       user addresses in the range addr to (addr+nbytes-1).  cache may be  one
       of:

       ICACHE Flush the instruction cache.

       DCACHE Write  back  to  memory  and invalidate the affected valid cache
              lines.

       BCACHE Same as (ICACHE|DCACHE).

RETURN VALUE
       cacheflush() returns 0 on success  or  -1  on  error.   If  errors  are
       detected, errno will indicate the error.

ERRORS
       EFAULT Some  or all of the address range addr to (addr+nbytes-1) is not
              accessible.

       EINVAL cache is not one of ICACHE, DCACHE, or BCACHE (but see BUGS).

CONFORMING TO
       Historically, this system calls was available on all MIPS UNIX variants
       including RISC/os, IRIX, Ultrix, NetBSD, OpenBSD, and FreeBSD (and also
       on some non-UNIX MIPS operating systems), so that the existence of this
       call in MIPS operating systems is a de-facto standard.

   Caveat
       cacheflush()  should  not  be used in programs intended to be portable.
       On Linux, this call first appeared on the MIPS architecture, but  nowa‐
       days, Linux provides a cacheflush() system call on some other architec‐
       tures, but with different arguments.

BUGS
       Linux kernels older than version 2.6.11  ignore  the  addr  and  nbytes
       arguments, making this function fairly expensive.  Therefore, the whole
       cache is always flushed.

       This function is always behaving as if BCACHE has been passed  for  the
       cache  argument  and  does not do any error checking on the cache argu‐
       ment.

COLOPHON
       This page is part of release 4.04 of the Linux  man-pages  project.   A
       description  of  the project, information about reporting bugs, and the
       latest    version    of    this    page,    can     be     found     at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-02-21                     CACHEFLUSH(2)
*/
