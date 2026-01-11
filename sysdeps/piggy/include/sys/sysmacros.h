#ifndef _SYS_SYSMACROS_H
#define _SYS_SYSMACROS_H

#ifdef __cplusplus
extern "C" {
#endif

#define major(dev) (((dev) & 0xff00u) >> 8)
#define minor(dev) ((dev) & 0x00ffu)
#define makedev(maj, min) ((((maj) << 8) & 0xff00u) | ((min) & 0x00ffu))

#ifdef __cplusplus
}
#endif

#endif /* _SYS_SYSMACROS_H */
