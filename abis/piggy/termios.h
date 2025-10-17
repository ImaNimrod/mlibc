#ifndef _ABIBITS_TERMIOS_H
#define _ABIBITS_TERMIOS_H

#define IGNBRK  0x00001
#define BRKINT  0x00002
#define IGNPAR  0x00004
#define PARMRK  0x00008
#define INPCK   0x00010
#define ISTRIP  0x00020
#define INLCR   0x00040
#define IGNCR   0x00080
#define ICRNL   0x00100
#define IUCLC   0x00200
#define IXON    0x00400
#define IXANY   0x00800
#define IXOFF   0x01000
#define IMAXBEL 0x02000
#define IUTF8   0x04000

#define OPOST   0x00001
#define OLCUC   0x00002
#define ONLCR   0x00004
#define OCRNL   0x00008
#define ONOCR   0x00010
#define ONLRET  0x00020
#define OFILL   0x00040

#define ISIG    0x00001
#define ICANON  0x00002
#define ECHO    0x00004
#define ECHOE   0x00008
#define ECHOK   0x00010
#define ECHONL  0x00020
#define NOFLSH  0x00040
#define TOSTOP  0x00080
#define ECHOCTL 0x00100
#define ECHOPRT 0x00200
#define ECHOKE  0x00400
#define IEXTEN  0x00800

#define CSIZE  0000060
#define CS5    0000000
#define CS6    0000020
#define CS7    0000040
#define CS8    0000060
#define CSTOPB 0000100
#define CREAD  0000200
#define PARENB 0000400
#define PARODD 0001000
#define HUPCL  0002000
#define CLOCAL 0004000
#define CBAUD  0010017

#define NCCS 32

#define VINTR     0
#define VQUIT     1
#define VERASE    2
#define VKILL     3
#define VEOF      4
#define VTIME     5
#define VMIN      6
#define VSWTC     7
#define VSTART    8
#define VSTOP     9
#define VSUSP    10
#define VEOL     11
#define VREPRINT 12
#define VDISCARD 13
#define VWERASE  14
#define VLNEXT   15
#define VEOL2    16

typedef unsigned char cc_t;
typedef unsigned int tcflag_t;
typedef unsigned int speed_t;

struct termios {
    tcflag_t c_iflag;
    tcflag_t c_oflag;
    tcflag_t c_cflag;
    tcflag_t c_lflag;
    cc_t c_line;
    cc_t c_cc[NCCS];
};

#endif /* _ABIBITS_TERMIOS_H */
