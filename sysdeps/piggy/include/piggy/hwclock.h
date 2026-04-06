#ifndef _PIGGY_HWCLOCK_H
#define _PIGGY_HWCLOCK_H

#define HWCLOCK_GETTIME 0x1001
#define HWCLOCK_SETTIME 0x1002

struct rtc_time {
    int second;
    int minute;
    int hour;
    int day;
    int month;
    int year;
};

#endif /* _PIGGY_HWCLOCK_H */
