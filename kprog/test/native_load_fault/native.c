/* Full-word BTF load used by the authorized guest recovery experiment. */
#include "vmlinux.h"
__attribute__((section("lsm/file_open"), used, noinline))
unsigned long entry(unsigned long *ctx)
{
    const struct file *file = (const void *)ctx[0];
    return *(const volatile unsigned long *)&file->f_pos;
}
