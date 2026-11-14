typedef unsigned long u64;

#ifndef TEST_DRIVER
u64 frame_map __attribute__((section(".maps")));
extern long bpf_tail_call(void *, void *, unsigned);
__attribute__((section("frame-test"), noinline))
u64 native_frame(u64 *ctx)
{
    volatile u64 values[24];
    for (unsigned i = 0; i < 24; ++i)
        values[i] = (ctx[0] + i * ctx[1]) ^ ctx[2];
    bpf_tail_call(ctx, &frame_map, (unsigned)ctx[3]);
    return values[ctx[4] % 24] + ctx[5];
}
#else
#include <stdio.h>
extern u64 frame_map;
extern u64 native_frame(u64 *);
static void *last_ctx, *last_map;
static unsigned last_index, calls;
long bpf_tail_call(void *ctx, void *map, unsigned index)
{
    last_ctx = ctx;
    last_map = map;
    last_index = index;
    ++calls;
    return 0;
}
int main(void)
{
    for (unsigned n = 0; n < 48; ++n) {
        u64 ctx[6] = {~(u64)n, n * 701, 0xfedcba9876543210UL,
                      0x100000000UL + n, n, n * 29};
        u64 expected = ((ctx[0] + (ctx[4] % 24) * ctx[1]) ^ ctx[2]) + ctx[5];
        if (native_frame(ctx) != expected || last_ctx != ctx ||
            last_map != &frame_map || last_index != n || calls != n + 1) {
            fprintf(stderr, "native frame behavior changed at vector %u\n", n);
            return 1;
        }
    }
    return 0;
}
#endif
