.global __mlibc_restorer

__mlibc_restorer:
    mov $46, %rax
    syscall
    ud2

#include <mlibc-asm/helpers.h>
GNU_STACK_NOTE()
