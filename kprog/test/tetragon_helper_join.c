#include <linux/bpf.h>
#define MICRO_NATIVE_TETRAGON
#define MICRO_NATIVE_HELPER_MACROS
#include "../../vendor/bpf/core-compat.h"

__attribute__((section("kprobe/test")))
int helper_join(unsigned long *ctx)
{
    return ctx[0] ? probe_read_kernel((void *)ctx[1], 4, (void *)ctx[2]) :
                    probe_read_user((void *)ctx[1], 4, (void *)ctx[2]);
}
