#include <bits/ensure.h>
#include <errno.h>
#include <piggy/piggy-sysdeps.hpp>
#include <sys/mount.h>

int mount(const char *source, const char *target, const char *fstype) {
	MLIBC_CHECK_OR_ENOSYS(mlibc::sys_mount, -1);
	if(int e = mlibc::sys_mount(source, target, fstype); e) {
		errno = e;
		return -1;
	}
	return 0;
}

int umount(const char *target) {
	MLIBC_CHECK_OR_ENOSYS(mlibc::sys_umount, -1);
	if(int e = mlibc::sys_umount(target); e) {
		errno = e;
		return -1;
	}
	return 0;
}
