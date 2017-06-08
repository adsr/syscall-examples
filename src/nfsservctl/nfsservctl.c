#define SYSCALL "nfsservctl"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
NFSSERVCTL(2)              Linux Programmer's Manual             NFSSERVCTL(2)

NAME
       nfsservctl - syscall interface to kernel nfs daemon

SYNOPSIS
       #include <linux/nfsd/syscall.h>

       long nfsservctl(int cmd, struct nfsctl_arg *argp,
                       union nfsctl_res *resp);

DESCRIPTION
       Note:  Since Linux 3.1, this system call no longer exists.  It has been
       replaced by a set of files in the nfsd filesystem; see nfsd(7).

       /*
        * These are the commands understood by nfsctl().
        *|
       #define NFSCTL_SVC          0    /* This is a server process. *|
       #define NFSCTL_ADDCLIENT    1    /* Add an NFS client. *|
       #define NFSCTL_DELCLIENT    2    /* Remove an NFS client. *|
       #define NFSCTL_EXPORT       3    /* Export a filesystem. *|
       #define NFSCTL_UNEXPORT     4    /* Unexport a filesystem. *|
       #define NFSCTL_UGIDUPDATE   5    /* Update a client's UID/GID map
                                           (only in Linux 2.4.x and earlier). *|
       #define NFSCTL_GETFH        6    /* Get a file handle (used by mountd)
                                           (only in Linux 2.4.x and earlier). *|

       struct nfsctl_arg {
           int                       ca_version;     /* safeguard *|
           union {
               struct nfsctl_svc     u_svc;
               struct nfsctl_client  u_client;
               struct nfsctl_export  u_export;
               struct nfsctl_uidmap  u_umap;
               struct nfsctl_fhparm  u_getfh;
               unsigned int          u_debug;
           } u;
       }

       union nfsctl_res {
               struct knfs_fh          cr_getfh;
               unsigned int            cr_debug;
       };

RETURN VALUE
       On success, zero is returned.  On error, -1 is returned, and  errno  is
       set appropriately.

CONFORMING TO
       This call is Linux-specific.

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-05-07                     NFSSERVCTL(2)
*/
