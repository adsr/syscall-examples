#define SYSCALL "reboot"
#include "common.h"

int run() {
    // TODO
    return 0;
}

/*
REBOOT(2)                  Linux Programmer's Manual                 REBOOT(2)

NAME
       reboot - reboot or enable/disable Ctrl-Alt-Del

SYNOPSIS
       /* For libc4 and libc5 the library call and the system call
          are identical, and since kernel version 2.1.30 there are
          symbolic names LINUX_REBOOT_* for the constants and a
          fourth argument to the call: *|

       #include <unistd.h>
       #include <linux/reboot.h>

       int reboot(int magic, int magic2, int cmd, void *arg);

       /* Under glibc and most alternative libc's (including uclibc, dietlibc,
          musl and a few others), some of the constants involved have gotten
          symbolic names RB_*, and the library call is a 1-argument
          wrapper around the 3-argument system call: *|

       #include <unistd.h>
       #include <sys/reboot.h>

       int reboot(int cmd);

DESCRIPTION
       The  reboot()  call  reboots the system, or enables/disables the reboot
       keystroke (abbreviated CAD, since the default  is  Ctrl-Alt-Delete;  it
       can be changed using loadkeys(1)).

       This   system   call  will  fail  (with  EINVAL)  unless  magic  equals
       LINUX_REBOOT_MAGIC1   (that   is,   0xfee1dead)   and   magic2   equals
       LINUX_REBOOT_MAGIC2  (that  is, 672274793).  However, since 2.1.17 also
       LINUX_REBOOT_MAGIC2A  (that  is,  85072278)  and  since   2.1.97   also
       LINUX_REBOOT_MAGIC2B   (that  is,  369367448)  and  since  2.5.71  also
       LINUX_REBOOT_MAGIC2C (that is, 537993216) are permitted as  values  for
       magic2.  (The hexadecimal values of these constants are meaningful.)

       The cmd argument can have the following values:

       LINUX_REBOOT_CMD_CAD_OFF
              (RB_DISABLE_CAD,  0).  CAD is disabled.  This means that the CAD
              keystroke will cause a SIGINT signal to be sent to init (process
              1),  whereupon  this  process  may  decide  upon a proper action
              (maybe: kill all processes, sync, reboot).

       LINUX_REBOOT_CMD_CAD_ON
              (RB_ENABLE_CAD, 0x89abcdef).  CAD is enabled.  This  means  that
              the  CAD  keystroke will immediately cause the action associated
              with LINUX_REBOOT_CMD_RESTART.

       LINUX_REBOOT_CMD_HALT
              (RB_HALT_SYSTEM, 0xcdef0123; since Linux 1.1.76).   The  message
              "System  halted." is printed, and the system is halted.  Control
              is given to the ROM monitor, if there is one.  If  not  preceded
              by a sync(2), data will be lost.

       LINUX_REBOOT_CMD_KEXEC
              (RB_KEXEC,  0x45584543,  since  Linux 2.6.13).  Execute a kernel
              that has been loaded earlier with kexec_load(2).  This option is
              available only if the kernel was configured with CONFIG_KEXEC.

       LINUX_REBOOT_CMD_POWER_OFF
              (RB_POWER_OFF,  0x4321fedc;  since  Linux  2.1.30).  The message
              "Power down." is printed, the system is stopped, and  all  power
              is  removed  from the system, if possible.  If not preceded by a
              sync(2), data will be lost.

       LINUX_REBOOT_CMD_RESTART
              (RB_AUTOBOOT, 0x1234567).  The message "Restarting  system."  is
              printed, and a default restart is performed immediately.  If not
              preceded by a sync(2), data will be lost.

       LINUX_REBOOT_CMD_RESTART2
              (0xa1b2c3d4; since Linux 2.1.30).  The message "Restarting  sys‐
              tem with command '%s'" is printed, and a restart (using the com‐
              mand string given in arg) is performed immediately.  If not pre‐
              ceded by a sync(2), data will be lost.

       LINUX_REBOOT_CMD_SW_SUSPEND
              (RB_SW_SUSPEND,  0xd000fce1; since Linux 2.5.18).  The system is
              suspended (hibernated) to disk.  This option is  available  only
              if the kernel was configured with CONFIG_HIBERNATION.

       Only the superuser may call reboot().

       The  precise  effect  of the above actions depends on the architecture.
       For the i386 architecture, the additional argument does not do anything
       at  present (2.1.122), but the type of reboot can be determined by ker‐
       nel command-line arguments ("reboot=...") to be either  warm  or  cold,
       and either hard or through the BIOS.

   Behavior inside PID namespaces
       Since  Linux  3.4,  when  reboot()  is called from a PID namespace (see
       pid_namespaces(7)) other than the initial PID namespace, the effect  of
       the  call  is  to  send  a  signal  to  the  namespace  "init" process.
       LINUX_REBOOT_CMD_RESTART and LINUX_REBOOT_CMD_RESTART2 cause  a  SIGHUP
       signal      to     be     sent.      LINUX_REBOOT_CMD_POWER_OFF     and
       LINUX_REBOOT_CMD_HALT cause a SIGINT signal to be sent.

RETURN VALUE
       For the values of cmd that stop or restart  the  system,  a  successful
       call  to  reboot()  does not return.  For the other cmd values, zero is
       returned on success.  In all cases, -1  is  returned  on  failure,  and
       errno is set appropriately.

ERRORS
       EFAULT Problem      with      getting     user-space     data     under
              LINUX_REBOOT_CMD_RESTART2.

       EINVAL Bad magic numbers or cmd.

       EPERM  The calling process has insufficient privilege to call reboot();
              the CAP_SYS_BOOT capability is required.

CONFORMING TO
       reboot() is Linux-specific, and should not be used in programs intended
       to be portable.

SEE ALSO
       kexec_load(2), sync(2), bootparam(7),  capabilities(7),  ctrlaltdel(8),
       halt(8), reboot(8)

COLOPHON
       This  page  is  part of release 4.04 of the Linux man-pages project.  A
       description of the project, information about reporting bugs,  and  the
       latest     version     of     this    page,    can    be    found    at
       http://www.kernel.org/doc/man-pages/.

Linux                             2015-12-05                         REBOOT(2)
*/
