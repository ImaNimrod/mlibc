#ifndef _ABIBITS_WAIT_H
#define _ABIBITS_WAIT_H

#define WNOHANG (1 << 0)

#define WEXITSTATUS(x) (((x) & 0xff00) >> 8)
#define WTERMSIG(x) ((x) & 0x7f)
#define WSTOPSIG(x) WEXITSTATUS(x)
#define WIFEXITED(x) (WTERMSIG(x) == 0)
#define WIFSIGNALED(x) (((signed char) (((x) & 0x7f) + 1) >> 1) > 0)

#endif /*_ABIBITS_WAIT_H */

