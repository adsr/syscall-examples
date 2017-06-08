#define SYSCALL "quotactl"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
QUOTACTL(2)                Linux Programmer's Manual               QUOTACTL(2)

NAME
       quotactl - manipulate disk quotas

SYNOPSIS
       #include <sys/quota.h>
       #include <xfs/xqm.h>

       int quotactl(int cmd, const char *special, int id, caddr_t addr);

DESCRIPTION
       The  quota  system  can be used to set per-user and per-group limits on
       the amount of disk space used on a filesystem.  For  each  user  and/or
       group,  a  soft  limit and a hard limit can be set for each filesystem.
       The hard limit can't be exceeded.  The soft limit can be exceeded,  but
       warnings  will  ensue.   Moreover, the user can't exceed the soft limit
       for more than one week (by default) at a time;  after  this  time,  the
       soft limit counts as a hard limit.

       The  quotactl()  call  manipulates disk quotas.  The cmd argument indi‐
       cates a command to be applied to the user or group ID specified in  id.
       To  initialize the cmd argument, use the QCMD(subcmd, type) macro.  The
       type value is either USRQUOTA, for user quotas, or GRPQUOTA, for  group
       quotas.  The subcmd value is described below.

       The  special argument is a pointer to a null-terminated string contain‐
       ing the pathname of the (mounted) block special device for the filesys‐
       tem being manipulated.

       The addr argument is the address of an optional, command-specific, data
       structure that is copied in or out of the system.   The  interpretation
       of addr is given with each command below.

       The subcmd value is one of the following:

       Q_QUOTAON
               Turn  on quotas for a filesystem.  The id argument is the iden‐
               tification number of the quota format to be  used.   Currently,
               there are three supported quota formats:

               QFMT_VFS_OLD The original quota format.

               QFMT_VFS_V0  The standard VFS v0 quota format, which can handle
                            32-bit UIDs and GIDs and quota limits up  to  2^42
                            bytes and 2^32 inodes.

               QFMT_VFS_V1  A  quota  format  that  can handle 32-bit UIDs and
                            GIDs and quota  limits  of  2^64  bytes  and  2^64
                            inodes.

               The  addr  argument points to the pathname of a file containing
               the quotas for the filesystem.  The quota file must  exist;  it
               is normally created with the quotacheck(8) program.  This oper‐
               ation requires privilege (CAP_SYS_ADMIN).

       Q_QUOTAOFF
               Turn off quotas for a filesystem.  The addr  and  id  arguments
               are     ignored.     This    operation    requires    privilege
               (CAP_SYS_ADMIN).

       Q_GETQUOTA
               Get disk quota limits and current usage for user or  group  id.
               The  addr argument is a pointer to a dqblk structure defined in
               <sys/quota.h> as follows:

                   /* uint64_t is an unsigned 64-bit integer;
                      uint32_t is an unsigned 32-bit integer *|

                   struct dqblk {          /* Definition since Linux 2.4.22 *|
                       uint64_t dqb_bhardlimit;   /* absolute limit on disk
                                                     quota blocks alloc *|
                       uint64_t dqb_bsoftlimit;   /* preferred limit on
                                                     disk quota blocks *|
                       uint64_t dqb_curspace;     /* current quota block
                                                     count *|
                       uint64_t dqb_ihardlimit;   /* maximum number of
                                                     allocated inodes *|
                       uint64_t dqb_isoftlimit;   /* preferred inode limit *|
                       uint64_t dqb_curinodes;    /* current number of
                                                     allocated inodes *|
                       uint64_t dqb_btime;        /* time limit for excessive
                                                     disk use *|
                       uint64_t dqb_itime;        /* time limit for excessive
                                                     files *|
                       uint32_t dqb_valid;        /* bit mask of QIF_*
                                                     constants *|
                   };

                   /* Flags in dqb_valid that indicate which fields in
                      dqblk structure are valid. *|

                   #define QIF_BLIMITS   1
                   #define QIF_SPACE     2
                   #define QIF_ILIMITS   4
                   #define QIF_INODES    8
                   #define QIF_BTIME     16
                   #define QIF_ITIME     32
                   #define QIF_LIMITS    (QIF_BLIMITS | QIF_ILIMITS)
                   #define QIF_USAGE     (QIF_SPACE | QIF_INODES)
                   #define QIF_TIMES     (QIF_BTIME | QIF_ITIME)
                   #define QIF_ALL       (QIF_LIMITS | QIF_USAGE | QIF_TIMES)

               The dqb_valid field is a bit mask that is set to  indicate  the
               entries  in the dqblk structure that are valid.  Currently, the
               kernel fills in all entries of the dqblk  structure  and  marks
               them  as  valid in the dqb_valid field.  Unprivileged users may
               retrieve   only   their   own   quotas;   a   privileged   user
               (CAP_SYS_ADMIN) can retrieve the quotas of any user.

       Q_SETQUOTA
               Set  quota information for user or group id, using the informa‐
               tion supplied in the dqblk structure pointed to by  addr.   The
               dqb_valid  field of the dqblk structure indicates which entries
               in the structure have been set by the caller.   This  operation
               supersedes  the Q_SETQLIM and Q_SETUSE operations in the previ‐
               ous  quota  interfaces.   This  operation  requires   privilege
               (CAP_SYS_ADMIN).

       Q_GETINFO
               Get  information  (like grace times) about quotafile.  The addr
               argument should be a  pointer  to  a  dqinfo  structure.   This
               structure is defined in <sys/quota.h> as follows:

                   /* uint64_t is an unsigned 64-bit integer;
                      uint32_t is an unsigned 32-bit integer *|

                   struct dqinfo {         /* Defined since kernel 2.4.22 *|
                       uint64_t dqi_bgrace;    /* Time before block soft limit
                                                  becomes hard limit *|

                       uint64_t dqi_igrace;    /* Time before inode soft limit
                                                  becomes hard limit *|
                       uint32_t dqi_flags;     /* Flags for quotafile
                                                  (DQF_*) *|
                       uint32_t dqi_valid;
                   };

                   /* Bits for dqi_flags *|

                   /* Quota format QFMT_VFS_OLD *|

                   #define V1_DQF_RSQUASH   1   /* Root squash enabled *|

                   /* Other quota formats have no dqi_flags bits defined *|

                   /* Flags in dqi_valid that indicate which fields in
                      dqinfo structure are valid. *|

                   # define IIF_BGRACE 1
                   # define IIF_IGRACE 2
                   # define IIF_FLAGS  4
                   # define IIF_ALL        (IIF_BGRACE | IIF_IGRACE | IIF_FLAGS)

               The  dqi_valid  field  in  the  dqinfo  structure indicates the
               entries in the structure that are valid.  Currently, the kernel
               fills in all entries of the dqinfo structure and marks them all
               as valid in the dqi_valid field.  The id argument is ignored.

       Q_SETINFO
               Set information about quotafile.  The addr argument should be a
               pointer  to  a  dqinfo  structure.   The dqi_valid field of the
               dqinfo structure indicates the entries in  the  structure  that
               have  been  set  by  the caller.  This operation supersedes the
               Q_SETGRACE and Q_SETFLAGS  operations  in  the  previous  quota
               interfaces.   The  id  argument  is  ignored.   This  operation
               requires privilege (CAP_SYS_ADMIN).

       Q_GETFMT
               Get quota format used on the specified  filesystem.   The  addr
               argument  should be a pointer to a 4-byte buffer where the for‐
               mat number will be stored.

       Q_SYNC  Update the on-disk copy of quota usages for a  filesystem.   If
               special  is  NULL,  then all filesystems with active quotas are
               sync'ed.  The addr and id arguments are ignored.

       Q_GETSTATS
               Get statistics and other generic information  about  the  quota
               subsystem.   The addr argument should be a pointer to a dqstats
               structure in which data should be stored.   This  structure  is
               defined  in  <sys/quota.h>.   The  special and id arguments are
               ignored.  This operation  is  obsolete  and  not  supported  by
               recent  kernels.  Files in /proc/sys/fs/quota/ carry the infor‐
               mation instead.

       For XFS filesystems making use of the  XFS  Quota  Manager  (XQM),  the
       above commands are bypassed and the following commands are used:

       Q_XQUOTAON
               Turn on quotas for an XFS filesystem.  XFS provides the ability
               to turn on/off quota limit enforcement with  quota  accounting.
               Therefore,  XFS expects addr to be a pointer to an unsigned int
               that  contains  either  the  flags  XFS_QUOTA_UDQ_ACCT   and/or
               XFS_QUOTA_UDQ_ENFD  (for  user  quota),  or  XFS_QUOTA_GDQ_ACCT
               and/or XFS_QUOTA_GDQ_ENFD (for  group  quota),  as  defined  in
               <xfs/xqm.h>.      This     operation     requires     privilege
               (CAP_SYS_ADMIN).

       Q_XQUOTAOFF
               Turn off quotas for an XFS filesystem.  As with Q_QUOTAON,  XFS
               filesystems  expect a pointer to an unsigned int that specifies
               whether quota accounting and/or limit enforcement  need  to  be
               turned off.  This operation requires privilege (CAP_SYS_ADMIN).

       Q_XGETQUOTA
               Get  disk quota limits and current usage for user id.  The addr
               argument is a pointer to an fs_disk_quota structure (defined in
               <xfs/xqm.h>).   Unprivileged  users may retrieve only their own
               quotas; a privileged user (CAP_SYS_ADMIN) may retrieve the quo‐
               tas of any user.

       Q_XSETQLIM
               Set  disk  quota  limits  for  user id.  The addr argument is a
               pointer to an fs_disk_quota structure (defined in <xfs/xqm.h>).
               This operation requires privilege (CAP_SYS_ADMIN).

       Q_XGETQSTAT
               Returns  an  fs_quota_stat structure containing XFS filesystem-
               specific quota information.  This is useful for finding out how
               much  space is used to store quota information, and also to get
               quotaon/off status of a given local XFS filesystem.

       Q_XQUOTARM
               Free the disk space taken by disk  quotas.   Quotas  must  have
               already been turned off.

       There  is  no command equivalent to Q_SYNC for XFS since sync(1) writes
       quota information to disk (in addition to the other filesystem metadata
       that it writes out).

RETURN VALUE
       On success, quotactl() returns 0; on error -1 is returned, and errno is
       set to indicate the error.

ERRORS
       EFAULT addr or special is invalid.

       EINVAL cmd or type is invalid.

       ENOENT The file specified by special or addr does not exist.

       ENOSYS The kernel has not been compiled with the CONFIG_QUOTA option.

       ENOTBLK
              special is not a block device.

       EPERM  The caller lacked the required privilege (CAP_SYS_ADMIN) for the
              specified operation.

       ESRCH  No  disk quota is found for the indicated user.  Quotas have not
              been turned on for this filesystem.

       If cmd is Q_SETQUOTA, quotactl() may also set errno to:

       ERANGE Specified limits are out of range allowed by quota format.

       If cmd is Q_QUOTAON, quotactl() may also set errno to:

       EACCES The quota file pointed to by addr exists, but is not  a  regular
              file;  or,  the quota file pointed to by addr exists, but is not
              on the filesystem pointed to by special.

       EBUSY  Q_QUOTAON attempted, but another Q_QUOTAON had already been per‐
              formed.

       EINVAL The quota file is corrupted.

       ESRCH  Specified quota format was not found.

SEE ALSO
       quota(1), getrlimit(2), quotacheck(8), quotaon(8)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2010-06-16                       QUOTACTL(2)
*/
