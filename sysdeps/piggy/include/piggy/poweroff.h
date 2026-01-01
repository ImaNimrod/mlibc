#ifndef _PIGGY_POWEROFF_H
#define _PIGGY_POWEROFF_H

#define POWEROFF_HALT       0x27baec8d
#define POWEROFF_REBOOT     0xce91fba2
#define POWEROFF_SHUTDOWN   0x19ba83ed

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __MLIBC_ABI_ONLY

int poweroff(int how);

#endif /* !__MLIBC_ABI_ONLY */

#ifdef __cplusplus
}
#endif

#endif /* _PIGGY_POWEROFF_H */
