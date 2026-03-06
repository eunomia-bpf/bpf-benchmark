#include "common.h"

struct simple_input_value {
    unsigned char data[64];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct simple_input_value);
} input_map SEC(".maps");

static __always_inline int bench_simple(const u8 *data, u32 len, u64 *out)
{
    (void)data;
    (void)len;
    *out = 12345678ULL;
    return 0;
}

DEFINE_MAP_BACKED_XDP_BENCH(simple_xdp, bench_simple, simple_input_value, 64U)
