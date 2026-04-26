#ifndef _PIGGY_SYSCALL_H
#define _PIGGY_SYSCALL_H

#define SYS_EXIT        0
#define SYS_FORK        1
#define SYS_EXEC        2
#define SYS_WAIT        3
#define SYS_GETPID      4
#define SYS_GETPPID     5
#define SYS_THREADNEW   6
#define SYS_THREADEXIT  7
#define SYS_GETTID      8
#define SYS_OPEN        9
#define SYS_MKDIR       10
#define SYS_RENAME      11
#define SYS_UNLINK      12
#define SYS_MOUNT       13
#define SYS_UNMOUNT     14
#define SYS_CLOSE       15
#define SYS_READ        16
#define SYS_WRITE       17
#define SYS_IOCTL       18
#define SYS_SEEK        19
#define SYS_TRUNCATE    20
#define SYS_POLL        21
#define SYS_SYNC        22
#define SYS_GETDENTS    23
#define SYS_STAT        24
#define SYS_UTIME       25
#define SYS_CHDIR       26
#define SYS_FCNTL       27
#define SYS_DUP         28
#define SYS_MMAP        29
#define SYS_MUNMAP      30
#define SYS_MPROTECT    31
#define SYS_CHROOT      32
#define SYS_PIPE        33
#define SYS_SLEEP       34
#define SYS_GETCLOCK    35
#define SYS_SETCLOCK    36
#define SYS_UNAME       37
#define SYS_FUTEX       38
#define SYS_POWEROFF    39
#define SYS_ARCHCTL     40

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
        : "memory", "rcx", "r11"
    );
    return ret;
}

static long syscall2(long n, long arg1, long arg2) {
    long ret;
    asm volatile(
        "syscall"
        : "=a"(ret)
        : "a"(n), "D"(arg1), "S"(arg2)
        : "memory", "rcx", "r11"
    );
    return ret;
}

static long syscall3(long n, long arg1, long arg2, long arg3) {
    long ret;
    asm volatile(
        "syscall"
        : "=a"(ret)
        : "a"(n), "D"(arg1), "S"(arg2), "d"(arg3)
        : "memory", "rcx", "r11"
    );
    return ret;
}

static long syscall4(long n, long arg1, long arg2, long arg3, long arg4) {
    register long r4 asm("r10") = arg4;

    long ret;
	asm volatile("syscall"
        : "=a"(ret)
		: "a"(n), "D"(arg1), "S"(arg2), "d"(arg3), "r"(r4)
		: "memory", "rcx", "r11"
    );
    return ret;
}

static long syscall5(long n, long arg1, long arg2, long arg3, long arg4, long arg5) {
    register long r4 asm("r10") = arg4;
    register long r5 asm("r8") = arg5;

    long ret;
    asm volatile (
        "syscall"
        : "=a"(ret)
        : "a"(n), "D"(arg1), "S"(arg2), "d"(arg3), "r"(r4), "r"(r5)
        : "memory", "rcx", "r11"
    );
    return ret;
}

static long syscall6(long n, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6) {
    register long r4 asm("r10") = arg4;
    register long r5 asm("r8") = arg5;
    register long r6 asm("r9") = arg6;

    long ret;
    asm volatile (
        "syscall"
        : "=a"(ret)
        : "a"(n), "D"(arg1), "S"(arg2), "d"(arg3), "r"(r4), "r"(r5), "r"(r6)
        : "memory", "rcx", "r11"
    );
    return ret;
}

#endif /* !__MLIBC_ABI_ONLY */

#endif /* _PIGGY_SYSCALL_H */
