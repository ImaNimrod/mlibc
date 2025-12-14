#ifndef _ABIBITS_FCNTL_H
#define _ABIBITS_FCNTL_H

#define O_PATH      01000

#define O_RDONLY    00000
#define O_WRONLY    00001
#define O_RDWR      00002
#define O_ACCMODE   (00003 | O_PATH)

#define O_CREAT     00004
#define O_DIRECTORY 00010
#define O_TRUNC     00020
#define O_APPEND    00040
#define O_EXCL      00100
#define O_NONBLOCK  00200
#define O_CLOEXEC   00400

#define F_DUPFD         0
#define F_GETFD         1
#define F_SETFD         2
#define F_GETFL         3
#define F_SETFL         4
#define F_DUPFD_CLOEXEC 1000

#define FD_CLOEXEC 1

#define AT_FDCWD -100

#define AT_EMPTY_PATH   (1 << 0)

/* NOT IMPLEMENTED BUT NEEDED TO COMPILE */
#define O_NOCTTY    0
#define O_NOFOLLOW  0
#define O_TMPFILE   0

#define F_RDLCK 0
#define F_WRLCK 0
#define F_UNLCK 0

#define F_GETLK     -1
#define F_SETLK     -1
#define F_SETLK64   F_SETLK
#define F_SETLKW    -1
#define F_SETLKW64  F_SETLKW

#define AT_SYMLINK_NOFOLLOW 0
#define AT_REMOVEDIR        0
#define AT_SYMLINK_FOLLOW   0
#define AT_EACCESS          0
#define AT_NO_AUTOMOUNT     0

#endif /* _ABIBITS_FCNTL_H */
