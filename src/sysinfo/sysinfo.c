#define SYSCALL "sysinfo"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
SYSINFO(2)                 Linux Programmer's Manual                SYSINFO(2)

NAME
       sysinfo - returns information on overall system statistics

SYNOPSIS
       #include <sys/sysinfo.h>

       int sysinfo(struct sysinfo *info);

DESCRIPTION
       Until Linux 2.3.16, sysinfo() used to return information in the follow‐
       ing structure:

           struct sysinfo {
               long uptime;             /* Seconds since boot *|
               unsigned long loads[3];  /* 1, 5, and 15 minute load averages *|
               unsigned long totalram;  /* Total usable main memory size *|
               unsigned long freeram;   /* Available memory size *|
               unsigned long sharedram; /* Amount of shared memory *|
               unsigned long bufferram; /* Memory used by buffers *|
               unsigned long totalswap; /* Total swap space size *|
               unsigned long freeswap;  /* swap space still available *|
               unsigned short procs;    /* Number of current processes *|
               char _f[22];             /* Pads structure to 64 bytes *|
           };

       and the sizes were given in bytes.

       Since Linux 2.3.23 (i386), 2.3.48 (all architectures) the structure is:

           struct sysinfo {
               long uptime;             /* Seconds since boot *|
               unsigned long loads[3];  /* 1, 5, and 15 minute load averages *|
               unsigned long totalram;  /* Total usable main memory size *|
               unsigned long freeram;   /* Available memory size *|
               unsigned long sharedram; /* Amount of shared memory *|
               unsigned long bufferram; /* Memory used by buffers *|
               unsigned long totalswap; /* Total swap space size *|
               unsigned long freeswap;  /* swap space still available *|
               unsigned short procs;    /* Number of current processes *|
               unsigned long totalhigh; /* Total high memory size *|
               unsigned long freehigh;  /* Available high memory size *|
               unsigned int mem_unit;   /* Memory unit size in bytes *|
               char _f[20-2*sizeof(long)-sizeof(int)]; /* Padding to 64 bytes *|
           };

       and the sizes are given as multiples of mem_unit bytes.

       sysinfo() provides a simple way of getting overall  system  statistics.
       This is more portable than reading /dev/kmem.

RETURN VALUE
       On  success,  zero is returned.  On error, -1 is returned, and errno is
       set appropriately.

ERRORS
       EFAULT pointer to struct sysinfo is invalid

VERSIONS
       The Linux kernel has a sysinfo() system call since 0.98.pl6.

CONFORMING TO
       This function is Linux-specific, and should not  be  used  in  programs
       intended to be portable.

SEE ALSO
       proc(5)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2014-08-19                        SYSINFO(2)
*/
