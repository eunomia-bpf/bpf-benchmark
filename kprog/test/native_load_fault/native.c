/* BTF read forms used by the authorized guest recovery experiment. */
#include "vmlinux.h"
__attribute__((section("lsm/file_open"), used, noinline))
unsigned long entry(unsigned long *ctx)
{
    const struct file *file = (const void *)ctx[0];
#if defined(__x86_64__) && defined(NATIVE_LOAD_FAULT_POP)
    __asm__ volatile("push %0; pop %0" : "+r"(file) : : "memory");
#endif
#if defined(NATIVE_LOAD_FAULT_CHAIN)
    unsigned long value = *(const volatile unsigned long *)&file->f_inode->i_ino;
#elif NATIVE_LOAD_FAULT_WIDTH == 8
    unsigned long value = *(const volatile unsigned char *)&file->f_pos;
#elif NATIVE_LOAD_FAULT_WIDTH == 16
    unsigned long value = *(const volatile unsigned short *)&file->f_pos;
#elif NATIVE_LOAD_FAULT_WIDTH == 32
    unsigned long value = *(const volatile unsigned int *)&file->f_pos;
#else
    unsigned long value = *(const volatile unsigned long *)&file->f_pos;
#endif
    return -(value & 1UL);
}
