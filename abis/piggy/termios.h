#ifndef _ABIBITS_TERMIOS_H
#define _ABIBITS_TERMIOS_H

#define BRKINT  0x0001
#define ICRNL   0x0002
#define IGNBRK  0x0004
#define IGNCR   0x0008
#define IGNPAR  0x0010
#define INLCR   0x0020
#define INPCK   0x0040
#define ISTRIP  0x0080
#define IXANY   0x0100
#define IXOFF   0x0200
#define IXON    0x0400
#define PARMRK  0x0800

#define OPOST   0x0001
#define ONLCR   0x0002
#define OCRNL   0x0004
#define ONOCR   0x0008
#define ONLRET  0x0010
#define OFILL   0x0020
#define OFDEL   0x0040

#define CBAUD   0x100f
#define CLOCAL  0x0010
#define CREAD   0x0020
#define CSIZE   0x00c0
#define CS5     0x0000
#define CS6     0x0040
#define CS7     0x0080
#define CS8     0x00c0
#define CSTOPB  0x0100
#define HUPCL   0x0200
#define PARENB  0x0400
#define PARODD  0x0800

#define ECHO    0x0001
#define ECHOE   0x0002
#define ECHOK   0x0004
#define ECHONL  0x0008
#define ICANON  0x0010
#define IEXTEN  0x0020
#define ISIG    0x0040
#define NOFLSH  0x0080
#define TOSTOP  0x0100

#define NCCS 16

#define VEOF    0
#define VEOL    1
#define VERASE  2
#define VINTR   3
#define VKILL   4
#define VMIN    5
#define VQUIT   6
#define VSUSP   7
#define VTIME   8
#define VSTART  9
#define VSTOP   10

typedef unsigned char cc_t;
typedef unsigned int tcflag_t;
typedef unsigned int speed_t;

struct termios {
    tcflag_t c_iflag;
    tcflag_t c_oflag;
    tcflag_t c_cflag;
    tcflag_t c_lflag;
    cc_t c_cc[NCCS];
};

#endif /* _ABIBITS_TERMIOS_H */
