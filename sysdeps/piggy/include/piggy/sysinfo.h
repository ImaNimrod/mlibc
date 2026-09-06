#ifndef _PIGGY_SYSINFO_H
#define _PIGGY_SYSINFO_H

#include <stddef.h>

struct sysinfo {
    size_t total_mem_pages;
    size_t free_mem_pages;
    char sysname[64];
    char hostname[256];
    char release[64];
    char version[64];
    char machine[64];
};

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __MLIBC_ABI_ONLY

int sysinfo(struct sysinfo* buf);

#endif /* !__MLIBC_ABI_ONLY */

#ifdef __cplusplus
}
#endif

#endif /* _PIGGY_SYSINFO_H */
