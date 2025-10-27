#ifndef _PIGGY_SYSCALL_H
#define _PIGGY_SYSCALL_H

#define SYS_EXIT        0
#define SYS_FORK        1
#define SYS_EXEC        2
#define SYS_WAIT        3
#define SYS_GETPID      4
#define SYS_GETPPID     5
#define SYS_GETTID      6
#define SYS_OPEN        7
#define SYS_MKDIR       8
#define SYS_UNLINK      9
#define SYS_MOUNT       10
#define SYS_UNMOUNT     11
#define SYS_CLOSE       12
#define SYS_READ        13
#define SYS_WRITE       14
#define SYS_IOCTL       15
#define SYS_SEEK        16
#define SYS_TRUNCATE    17
#define SYS_STAT        18
#define SYS_CHDIR       19
#define SYS_FCNTL       20
#define SYS_DUP         21
#define SYS_SBRK        22
#define SYS_SLEEP       23
#define SYS_GETTIME     24
#define SYS_SETTIME     25
#define SYS_UNAME       26
#define SYS_ARCHCTL     27

#ifndef __MLIBC_ABI_ONLY

static long syscall0(long n) {
    long ret;
    asm volatile(
        "syscall"
        : "=a"(ret)
        : "a"(n)
        : "rcx", "r11", "memory"
    );
    return ret;
}

static long syscall1(long n, long arg1) {
    long ret;
    asm volatile(
        "syscall"
        : "=a"(ret)
        : "a"(n), "D"(arg1)
        : "rcx", "r11", "memory"
    );
    return ret;
}

static long syscall2(long n, long arg1, long arg2) {
    long ret;
    asm volatile(
        "syscall"
        : "=a"(ret)
        : "a"(n), "D"(arg1), "S"(arg2)
        : "rcx", "r11", "memory"
    );
    return ret;
}

static long syscall3(long n, long arg1, long arg2, long arg3) {
    long ret;
    asm volatile(
        "syscall"
        : "=a"(ret)
        : "a"(n), "D"(arg1), "S"(arg2), "d"(arg3)
        : "rcx", "r11", "memory"
    );
    return ret;
}

#endif /* !__MLIBC_ABI_ONLY */

#endif /* _PIGGY_SYSCALL_H */
