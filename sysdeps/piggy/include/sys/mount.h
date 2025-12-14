#ifndef _SYS_MOUNT_H
#define _SYS_MOUNT_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __MLIBC_ABI_ONLY

int mount(const char *__source, const char *__target,
		const char *__fstype, unsigned long __flags, const void *__data);
int umount(const char *__target);

#endif /* !__MLIBC_ABI_ONLY */

#ifdef __cplusplus
}
#endif

#endif /* _SYS_MOUNT_H */
