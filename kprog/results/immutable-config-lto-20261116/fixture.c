#include <stdint.h>
#include <stdatomic.h>

const volatile uint32_t enabled = 1;
const volatile int64_t signed_config = -1;
volatile uint32_t mutable_value = 7;
_Atomic uint32_t ordered_value = 9;
const volatile struct { uint32_t a, b; } aggregate = {11, 13};
extern long bpf_probe_read_kernel(void *, unsigned long, const void *);

long entry(void *ctx)
{
    if (enabled)
        return bpf_probe_read_kernel(ctx, 8, ctx);
    return signed_config + mutable_value + aggregate.a +
        atomic_load_explicit(&ordered_value, memory_order_seq_cst);
}
