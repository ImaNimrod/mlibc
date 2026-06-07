#ifndef _PIGGY_SYSCALL_H
#define _PIGGY_SYSCALL_H

#define SYS_EXIT        0
#define SYS_FORK        1
#define SYS_EXEC        2
#define SYS_WAIT        3
#define SYS_KILL        4
#define SYS_GETPID      5
#define SYS_GETPPID     6
#define SYS_THREADNEW   7
#define SYS_THREADEXIT  8
#define SYS_GETTID      9
#define SYS_YIELD       10
#define SYS_OPEN        11
#define SYS_MKDIR       12
#define SYS_RENAME      13
#define SYS_UNLINK      14
#define SYS_MOUNT       15
#define SYS_UNMOUNT     16
#define SYS_CLOSE       17
#define SYS_READ        18
#define SYS_WRITE       19
#define SYS_PREAD       20
#define SYS_PWRITE      21
#define SYS_IOCTL       22
#define SYS_SEEK        23
#define SYS_TRUNCATE    24
#define SYS_POLL        25
#define SYS_SYNC        26
#define SYS_GETDENTS    27
#define SYS_STAT        28
#define SYS_UTIME       29
#define SYS_CHDIR       30
#define SYS_FCNTL       31
#define SYS_DUP         32
#define SYS_MMAP        33
#define SYS_MUNMAP      34
#define SYS_MPROTECT    35
#define SYS_CHROOT      36
#define SYS_PIPE        37
#define SYS_SLEEP       38
#define SYS_GETCLOCK    39
#define SYS_GETCLOCKRES 40
#define SYS_SETCLOCK    41
#define SYS_SIGACTION   42
#define SYS_SIGALTSTACK 43
#define SYS_SIGPENDING  44
#define SYS_SIGPROCMASK 45
#define SYS_SIGRETURN   46
#define SYS_SIGSUSPEND  47
#define SYS_UNAME       48
#define SYS_FUTEX       49
#define SYS_POWEROFF    50
#define SYS_ARCHCTL     51

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
