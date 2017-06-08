#define SYSCALL "_llseek"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
LLSEEK(2)                  Linux Programmer's Manual                 LLSEEK(2)

NAME
       _llseek - reposition read/write file offset

SYNOPSIS
       #include <sys/types.h>
       #include <unistd.h>

       int _llseek(unsigned int fd, unsigned long offset_high,
                   unsigned long offset_low, loff_t *result,
                   unsigned int whence);

       Note: There is no glibc wrapper for this system call; see NOTES.

DESCRIPTION
       The  _llseek() function repositions the offset of the open file associ‐
       ated with the file descriptor  fd  to  (offset_high<<32)  |  offset_low
       bytes  relative  to  the beginning of the file, the current position in
       the file, or the end of  the  file,  depending  on  whether  whence  is
       SEEK_SET,  SEEK_CUR, or SEEK_END, respectively.  It returns the result‐
       ing file position in the argument result.

       This system call exists on various 32-bit platforms to support  seeking
       to large file offsets.

RETURN VALUE
       Upon successful completion, _llseek() returns 0.  Otherwise, a value of
       -1 is returned and errno is set to indicate the error.

ERRORS
       EBADF  fd is not an open file descriptor.

       EFAULT Problem with copying results to user space.

       EINVAL whence is invalid.

CONFORMING TO
       This function is Linux-specific, and should not  be  used  in  programs
       intended to be portable.

NOTES
       Glibc  does  not  provide a wrapper for this system call.  To invoke it
       directly, use syscall(2).   However,  you  probably  want  to  use  the
       lseek(2) wrapper function instead.

SEE ALSO
       lseek(2), lseek64(3)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-04-19                         LLSEEK(2)
*/
