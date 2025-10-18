#include <bits/ensure.h>
#include <mlibc/debug.hpp>
#include <mlibc/all-sysdeps.hpp>
#include <errno.h>
#include <piggy/syscall.h>
#include <piggy/archctl.h>
#include <string.h>
#include <stdlib.h>
#include <asm/ioctls.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

namespace mlibc {
    [[noreturn]] void sys_exit(int status) {
        syscall1(SYS_EXIT, status);
        __builtin_unreachable();
    }

    int sys_fork(pid_t *pid) {
        long ret = syscall0(SYS_FORK);
        if (ret < 0) {
            return -ret;
        }

        *pid = ret;
        return 0;
    }


    int sys_execve(const char *path, char *const argv[], char *const envp[]) {
        long ret = syscall3(SYS_EXEC, (long) path, (long) argv, (long) envp);
        if (ret < 0) {
            return -ret;
        }
        return 0;
    }

    /*
	int sys_waitpid(pid_t pid, int *status, int flags, struct rusage *ru, pid_t *ret_pid) {
		(void)ru;
		long ret;
		long err = syscall(SYS_WAITPID, &ret, pid, (uint64_t)status, flags);
		*ret_pid = ret;
		return err;
	}
    */

    pid_t sys_getpid() {
        return syscall0(SYS_GETPID);
    }

	pid_t sys_getppid() {
        return syscall0(SYS_GETPPID);
	}

    int sys_openat(int dirfd, const char *path, int flags, mode_t mode, int *fd) {
        (void) mode;

        long ret = syscall3(SYS_OPEN, dirfd, (long) path, flags);
        if (ret < 0) {
            return -ret;
        }

        *fd = ret;
        return 0;
    }

	int sys_open(const char *pathname, int flags, mode_t mode, int *fd) {
		return sys_openat(AT_FDCWD, pathname, flags, mode, fd);
	};

    int sys_open_dir(const char *path, int *handle) {
        return sys_open(path, O_DIRECTORY, 0, handle);
    }

    int sys_mkdirat(int dirfd, const char *path, mode_t mode) {
        (void) mode;

        long ret = syscall2(SYS_MKDIR, dirfd, (long) path);
        if (ret < 0) {
            return -ret;
        }
        return 0;
    }

    int sys_mkdir(const char *path, mode_t mode) {
        return sys_mkdirat(AT_FDCWD, path, mode);
    }

    int sys_unlinkat(int fd, const char *path, int flags) {
        (void) flags;

        long ret = syscall2(SYS_UNLINK, fd, (long) path);
        if (ret < 0) {
            return -ret;
        }
        return 0;
    }

    int sys_rmdir(const char *path) {
        return sys_unlinkat(AT_FDCWD, path, 0);
    }

    int sys_mount(const char *source, const char *target, const char *fstype, unsigned long flags, const void *data) {
        (void) flags;
        (void) data;

        long ret = syscall3(SYS_MOUNT, (long) source, (long) target, (long) fstype);
        if (ret < 0) {
            return -ret;
        }
        return 0;
    }


    int sys_close(int fd) {
        long ret = syscall1(SYS_CLOSE, fd);
        if (ret < 0) {
            return -ret;
        }
        return 0;
    }


    int sys_read(int fd, void *buff, size_t count, ssize_t *bytes_read) {
        long ret = syscall3(SYS_READ, fd, (long) buff, count);
        if (ret < 0) {
            return -ret;
        }

        *bytes_read = ret;
        return 0;
    }

    int sys_write(int fd, const void *buff, size_t count, ssize_t *bytes_written) {
        long ret = syscall3(SYS_WRITE, fd, (long) buff, count);
        if (ret < 0) {
            return -ret;
        }

        *bytes_written = ret;
        return 0;
    }

    int sys_ioctl(int fd, unsigned long request, void *arg, int *result) {
        long ret = syscall3(SYS_IOCTL, fd, request, (long) arg);
        if (ret < 0) {
            return -ret;
        }

        *result = ret;
        return 0;
    }

    int sys_seek(int fd, off_t offset, int whence, off_t *new_offset) {
        long ret = syscall3(SYS_SEEK, fd, offset, whence);
        if (ret < 0) {
            return -ret;
        }

        *new_offset = ret;
        return 0;
    }

    /*
	int sys_stat(fsfd_target fsfdt, int fd, const char *path, int flags, struct stat *statbuf) {
		long ret;
		switch (fsfdt) {
			case fsfd_target::path:
				return syscall(SYS_FSTATAT, &ret, AT_FDCWD, (uint64_t)path, (uint64_t)statbuf, flags);
			case fsfd_target::fd:
				return syscall(SYS_FSTAT, &ret, fd, (uint64_t)statbuf);
			case fsfd_target::fd_path:
				return syscall(SYS_FSTATAT, &ret, fd, (uint64_t)path, (uint64_t)statbuf, flags);
			default:
				mlibc::infoLogger() << "mlibc: stat: Unknown fsfd_target: " << (int)fsfdt << frg::endlog;
				return ENOSYS;
		}
	}
    */

    int sys_ftruncate(int fd, size_t size) {
        long ret = syscall2(SYS_TRUNCATE, fd, size);
        if (ret < 0) {
            return -ret;
        }
        return 0;
    }


    int sys_chdir(const char *path) {
        int fd;
        int ret = sys_open_dir(path, &fd);
        if (ret < 0) {
            return ret;
        }

        ret = sys_fchdir(fd);

        sys_close(fd);
        return ret;
    }

    int sys_fchdir(int fd) {
        long ret = syscall1(SYS_CHDIR, fd);
        if (ret < 0) {
            return -ret;
        }
        return 0;
    }

    int sys_fcntl(int fd, int request, va_list args, int *result) {
        long arg = va_arg(args, long);

        long ret = syscall3(SYS_FCNTL, fd, request, arg);
        if (ret < 0) {
            return -ret;
        }

        *result = ret;
        return 0;
    }

    int sys_dup(int fd, int flags, int *newfd) {
        (void) flags;
        return sys_fcntl(fd, F_DUPFD, 0, newfd);
    }

    /*
	int sys_dup2(int fd, int flags, int newfd) {
		(void)flags;
		long ret;
		return syscall(SYS_DUP2, &ret, fd, newfd);
	}
    */

    int sys_isatty(int fd) {
        struct winsize ws;
        int ret;

        if (sys_ioctl(fd, TIOCGWINSZ, &ws, &ret) == 0) {
            return 0;
        }

        return ENOTTY;
    }

    int sys_tcgetattr(int fd, struct termios *attr){
        int res;
        return sys_ioctl(fd, TCGETS, (void*) attr, &res);
    }

    int sys_tcsetattr(int fd, int act, const struct termios *attr){
        (void) act;

        int res;
        return sys_ioctl(fd, TCSETS, (void*) attr, &res);
    }

    int sys_sleep(time_t *secs, long *nanos) {
        struct timespec ts;
        ts.tv_sec = *secs;
        ts.tv_nsec = *nanos;

        long ret = syscall1(SYS_SLEEP, (long) &ts);
        if (ret < 0) {
            return -ret;
        }
        return 0;
    }

    int sys_clock_get(int clock, time_t *secs, long *nanos) {
        struct timespec ts;

        long ret = syscall2(SYS_GETTIME, clock, (uint64_t)&ts);
        if (ret < 0) {
            return -ret;
        }

        *secs = ts.tv_sec;
        *nanos = ts.tv_nsec;
        return 0;
    }

    int sys_clock_set(int clock, time_t secs, long nanos) {
        struct timespec ts = { .tv_sec = secs, .tv_nsec = nanos };

        long ret = syscall2(SYS_SETTIME, clock, (uint64_t) &ts);
        if (ret < 0) {
            return -ret;
        }
        return 0;
    }

    int sys_futex_tid() {
        return syscall0(SYS_GETTID);
    }

    int sys_futex_wait(int *pointer, int expected, const struct timespec *time) {
        (void) pointer;
        (void) expected;
        (void) time;
        sys_libc_log("futex_wait\n");
        return 0;
    }

    int sys_futex_wake(int *pointer) {
        (void) pointer;
        sys_libc_log("futex_wake\n");
        return 0;
    }

    int sys_tcb_set(void* pointer) {
        long ret = syscall2(SYS_ARCHCTL, ARCHCTL_SET_FSBASE, (long) pointer);
        if (ret < 0) {
            return -ret;
        }
        return 0;
    }

    int sys_uname(struct utsname *buf) {
        long ret = syscall1(SYS_UNAME, (long) buf);
        if (ret < 0) {
            return -ret;
        }
        return 0;
    }

    int sys_vm_map(void *hint, size_t size, int prot, int flags, int fd, off_t offset, void **window) {
        (void) hint;
        (void) prot;
        (void) flags;
        (void) fd;
        (void) offset;

        long ret = syscall1(SYS_SBRK, size);
        if (ret < 0) {
            return -ret;
        }

        *window = (void*) ret;
        return 0;
    }

    int sys_vm_unmap(void *pointer, size_t size) {
        (void) pointer;
        (void) size;
        return 0;
	}

    int sys_anon_allocate(size_t size, void **pointer) {
        return sys_vm_map(nullptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,
                -1, 0, pointer);
    }

    int sys_anon_free(void *pointer, size_t size) {
        return sys_vm_unmap(pointer, size);
    }

    uid_t sys_getuid() {
        return 0;
    }

    uid_t sys_geteuid() {
        return 0;
    }

    gid_t sys_getgid() {
        return 0;
    }

    gid_t sys_getegid() {
        return 0;
    }

    int sys_getresuid(uid_t *ruid, uid_t *euid, uid_t *suid) {
        *ruid = *euid = *suid = 0;
        return 0;
    }

    int sys_getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid) {
        *rgid = *egid = *sgid = 0;
        return 0;
    }

    void sys_libc_log(const char *message) {
        long ret;
        sys_write(2, message, strlen(message), &ret);
        sys_write(2, "\n", 1, &ret);
    }
	
	[[noreturn]] void sys_libc_panic() {
		sys_libc_log("mlibc: panic");
		sys_exit(1);
	}
} // namespace mlibc
