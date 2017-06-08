#define SYSCALL "uselib"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
USELIB(2)                  Linux Programmer's Manual                 USELIB(2)

NAME
       uselib - load shared library

SYNOPSIS
       #include <unistd.h>

       int uselib(const char *library);

DESCRIPTION
       The  system call uselib() serves to load a shared library to be used by
       the calling process.  It is given a pathname.   The  address  where  to
       load  is  found in the library itself.  The library can have any recog‐
       nized binary format.

RETURN VALUE
       On success, zero is returned.  On error, -1 is returned, and  errno  is
       set appropriately.

ERRORS
       In  addition to all of the error codes returned by open(2) and mmap(2),
       the following may also be returned:

       EACCES The library specified by library does not have read  or  execute
              permission,  or  the  caller does not have search permission for
              one of the directories in the path prefix.  (See also path_reso‐
              lution(7).)

       ENFILE The system-wide limit on the total number of open files has been
              reached.

       ENOEXEC
              The file specified by library is not an executable  of  a  known
              type; for example, it does not have the correct magic numbers.

CONFORMING TO
       uselib() is Linux-specific, and should not be used in programs intended
       to be portable.

NOTES
       uselib() was used by  early  libc  startup  code  to  load  the  shared
       libraries with names found in an array of names in the binary.

       Since  libc  4.3.2,  startup  code  tries  to  prefix  these names with
       "/usr/lib", "/lib" and "" before giving up.  In libc  4.3.4  and  later
       these names are looked for in the directories found in LD_LIBRARY_PATH,
       and if not found there, prefixes "/usr/lib", "/lib" and "/" are tried.

       From libc 4.4.4 on only the library "/lib/ld.so"  is  loaded,  so  that
       this  dynamic  library  can  load the remaining libraries needed (again
       using this call).  This is also the state of affairs in libc5.

       glibc2 does not use this call.

SEE ALSO
       ar(1), gcc(1), ld(1), ldd(1), mmap(2),  open(2),  dlopen(3),  capabili‐
       ties(7), ld.so(8)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-12-28                         USELIB(2)
*/
