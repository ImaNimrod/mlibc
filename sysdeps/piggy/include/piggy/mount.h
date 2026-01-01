#ifndef _PIGGY_MOUNT_H
#define _PIGGY_MOUNT_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __MLIBC_ABI_ONLY

int mount(const char *source, const char *target, const char *fstype);
int umount(const char *target);

#endif /* !__MLIBC_ABI_ONLY */

#ifdef __cplusplus
}
#endif

#endif /* _PIGGY_MOUNT_H */
