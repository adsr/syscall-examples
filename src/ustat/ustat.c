#define SYSCALL "ustat"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
USTAT(2)                   Linux Programmer's Manual                  USTAT(2)

NAME
       ustat - get filesystem statistics

SYNOPSIS
       #include <sys/types.h>
       #include <unistd.h>    /* libc[45] *|
       #include <ustat.h>     /* glibc2 *|

       int ustat(dev_t dev, struct ustat *ubuf);

DESCRIPTION
       ustat()  returns  information  about  a  mounted  filesystem.  dev is a
       device number identifying a device  containing  a  mounted  filesystem.
       ubuf is a pointer to a ustat structure that contains the following mem‐
       bers:

           daddr_t f_tfree;      /* Total free blocks *|
           ino_t   f_tinode;     /* Number of free inodes *|
           char    f_fname[6];   /* Filsys name *|
           char    f_fpack[6];   /* Filsys pack name *|

       The last two fields, f_fname and f_fpack, are not implemented and  will
       always be filled with null bytes ('\0').

RETURN VALUE
       On success, zero is returned and the ustat structure pointed to by ubuf
       will be filled in.  On error, -1 is returned, and errno is  set  appro‐
       priately.

ERRORS
       EFAULT ubuf points outside of your accessible address space.

       EINVAL dev does not refer to a device containing a mounted filesystem.

       ENOSYS The  mounted  filesystem referenced by dev does not support this
              operation, or any version of Linux before 1.3.16.

CONFORMING TO
       SVr4.

NOTES
       ustat() is deprecated and has been  provided  only  for  compatibility.
       All new programs should use statfs(2) instead.

   HP-UX notes
       The  HP-UX  version  of  the  ustat  structure has an additional field,
       f_blksize, that is unknown elsewhere.  HP-UX warns: For  some  filesys‐
       tems, the number of free inodes does not change.  Such filesystems will
       return -1 in the field f_tinode.   For  some  filesystems,  inodes  are
       dynamically allocated.  Such filesystems will return the current number
       of free inodes.

SEE ALSO
       stat(2), statfs(2)

COLOPHON
       This page is part of release 4.04 of the Linux  man-pages  project.   A
       description  of  the project, information about reporting bugs, and the
       latest    version    of    this    page,    can     be     found     at
       http://www.kernel.org/doc/man-pages/.

Linux                             2003-08-04                          USTAT(2)
*/
