#ifndef _ABIBITS_STAT_H
#define _ABIBITS_STAT_H

#include <abi-bits/blkcnt_t.h>
#include <abi-bits/blksize_t.h>
#include <abi-bits/dev_t.h>
#include <abi-bits/ino_t.h>
#include <abi-bits/mode_t.h>
#include <bits/ansi/timespec.h>
#include <bits/off_t.h>

#define S_IFMT  0x0f000
#define S_IFREG 0x01000
#define S_IFDIR 0x03000
#define S_IFBLK 0x05000
#define S_IFCHR 0x07000
#define S_IFLNK 0x09000

#define S_IRWXU 0700
#define S_IRUSR 0400
#define S_IWUSR 0200
#define S_IXUSR 0100
#define S_IRWXG 070
#define S_IRGRP 040
#define S_IWGRP 020
#define S_IXGRP 010
#define S_IRWXO 07
#define S_IROTH 04
#define S_IWOTH 02
#define S_IXOTH 01

#ifdef __cplusplus
extern "C" {
#endif

struct stat {
    dev_t st_dev;
    ino_t st_ino;
    mode_t st_mode;
    dev_t st_rdev;
    off_t st_size;
    blksize_t st_blksize;
    blkcnt_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
};

#define stat64 stat

#ifdef __cplusplus
}
#endif

#endif /* _ABIBITS_STAT_H */
