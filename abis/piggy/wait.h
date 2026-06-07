#ifndef _ABIBITS_WAIT_H
#define _ABIBITS_WAIT_H

#define WNOHANG (1 << 0)

#define WEXITSTATUS(x)  ((x) & 0xff)
#define WTERMSIG(x)     (((x) & 0x7f00) >> 8)
#define WSTOPSIG(x)     WEXITSTATUS(x)
#define WIFEXITED(x)    (WTERMSIG(x) == 0)
#define WIFSIGNALED(x)  (WTERMSIG(x) != 0)
#define WIFSTOPPED(x)   (((x) & 0xff) == 0x7f)
#define WIFCONTINUED(x) ((x) == 0xffff)

#endif /*_ABIBITS_WAIT_H */
