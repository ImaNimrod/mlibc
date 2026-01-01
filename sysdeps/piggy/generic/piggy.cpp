#include <errno.h>
#include <piggy/archctl.h>
#include <piggy/mount.h>
#include <piggy/poweroff.h>
#include <piggy/syscall.h>

#ifndef MLIBC_BUILDING_RTLD

int archctl(int op, void *arg) {
    long ret = syscall2(SYS_ARCHCTL, op, (long) arg);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int mount(const char *source, const char *target, const char *fstype) {
    long ret = syscall3(SYS_MOUNT, (long) source, (long) target, (long) fstype);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int umount(const char *target) {
    long ret = syscall1(SYS_UNMOUNT, (long) target);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int poweroff(int how) {
    long ret = syscall1(SYS_POWEROFF, how);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

#endif
