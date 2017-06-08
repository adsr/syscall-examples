#define SYSCALL "acct"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
ACCT(2)                    Linux Programmer's Manual                   ACCT(2)

NAME
       acct - switch process accounting on or off

SYNOPSIS
       #include <unistd.h>

       int acct(const char *filename);

   Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

       acct(): _BSD_SOURCE || (_XOPEN_SOURCE && _XOPEN_SOURCE < 500)

DESCRIPTION
       The  acct()  system  call  enables  or disables process accounting.  If
       called with the name of an existing file as its argument, accounting is
       turned  on,  and  records  for each terminating process are appended to
       filename as it terminates.  An argument of NULL causes accounting to be
       turned off.

RETURN VALUE
       On  success,  zero is returned.  On error, -1 is returned, and errno is
       set appropriately.

ERRORS
       EACCES Write permission is denied for the  specified  file,  or  search
              permission is denied for one of the directories in the path pre‐
              fix of filename (see also path_resolution(7)),  or  filename  is
              not a regular file.

       EFAULT filename points outside your accessible address space.

       EIO    Error writing to the file filename.

       EISDIR filename is a directory.

       ELOOP  Too many symbolic links were encountered in resolving filename.

       ENAMETOOLONG
              filename was too long.

       ENFILE The system-wide limit on the total number of open files has been
              reached.

       ENOENT The specified filename does not exist.

       ENOMEM Out of memory.

       ENOSYS BSD process accounting has not been enabled when  the  operating
              system  kernel was compiled.  The kernel configuration parameter
              controlling this feature is CONFIG_BSD_PROCESS_ACCT.

       ENOTDIR
              A component used as a directory in filename is  not  in  fact  a
              directory.

       EPERM  The calling process has insufficient privilege to enable process
              accounting.  On Linux the CAP_SYS_PACCT capability is required.

       EROFS  filename refers to a file on a read-only filesystem.

       EUSERS There are no more free file structures or we ran out of memory.

CONFORMING TO
       SVr4, 4.3BSD (but not POSIX).

NOTES
       No accounting is produced for programs  running  when  a  system  crash
       occurs.   In  particular,  nonterminating processes are never accounted
       for.

       The structure  of  the  records  written  to  the  accounting  file  is
       described in acct(5).

SEE ALSO
       acct(5)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-12-28                           ACCT(2)
*/
