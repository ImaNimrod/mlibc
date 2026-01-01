#ifndef _PIGGY_ARCHCTL_H
#define _PIGGY_ARCHCTL_H

#define ARCHCTL_GET_FSBASE 0
#define ARCHCTL_GET_GSBASE 1
#define ARCHCTL_SET_FSBASE 2
#define ARCHCTL_SET_GSBASE 3

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __MLIBC_ABI_ONLY

int archctl(int op, void *arg);

#endif /* !__MLIBC_ABI_ONLY */

#ifdef __cplusplus
}
#endif

#endif /* _PIGGY_ARCHCTL_H */
