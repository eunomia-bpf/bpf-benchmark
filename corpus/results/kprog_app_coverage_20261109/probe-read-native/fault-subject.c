/* Exercise the producer rewrite with the existing live/NULL guest module. */
#include "vmlinux.h"
__attribute__((section("lsm/file_open"), used, noinline))
unsigned long entry(unsigned long *context)
{
    const struct file *file = (const void *)context[0];
    unsigned long value = ~0UL, zero = ~0UL, user_zero = ~0UL;
    const unsigned long mask = ~0UL >> (64 - PROBE_WIDTH * 8);
    const void *source = file ? (const void *)&file->f_pos :
                               (const void *)(0UL - PROBE_WIDTH);
    long result = bpf_probe_read_kernel(&value, PROBE_WIDTH, source);
    if (!file)
        return result == -14 && (value & mask) == 0 ? 0 : 2;
    long zero_result = bpf_probe_read_kernel(&zero, PROBE_WIDTH, &file->f_flags);
    long user_result = bpf_probe_read_kernel(&user_zero, PROBE_WIDTH, (const void *)0);
    if (result || zero_result || (zero & mask) || user_result != -14 || (user_zero & mask))
        return 2;
    return -(value & 1UL);
}
