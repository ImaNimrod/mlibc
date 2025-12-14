#ifndef MLIBC_PIGGY_SYSDEPS
#define MLIBC_PIGGY_SYSDEPS

namespace  [[gnu::visibility("hidden")]] mlibc {

[[gnu::weak]] int sys_mount(const char *source, const char *target, const char *fstype);
[[gnu::weak]] int sys_umount(const char *target);

} // namespace mlibc

#endif // MLIBC_PIGGY_SYSDEPS
