#include "common.h"

#define GET_TIME_HEAVY_MAX_CALLS 128U
#define GET_TIME_HEAVY_INPUT_SIZE 4U

struct get_time_heavy_input_value {
    unsigned char data[GET_TIME_HEAVY_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct get_time_heavy_input_value);
} input_map SEC(".maps");

static __always_inline int bench_get_time_heavy(const u8 *data, u32 len, u64 *out)
{
    u64 acc = 0;
    u32 count;

    if (!micro_has_bytes(len, 0, GET_TIME_HEAVY_INPUT_SIZE)) {
        return -1;
    }

    count = micro_read_u32_le(data, 0);
    if (count != GET_TIME_HEAVY_MAX_CALLS) {
        return -1;
    }

    for (u32 i = 0; i < GET_TIME_HEAVY_MAX_CALLS; i++) {
        u64 now = bpf_ktime_get_ns();

        acc = micro_rotl64(acc, 7) ^ now;
    }

    *out = acc;
    return 0;
}

DEFINE_MAP_BACKED_XDP_BENCH(
    get_time_heavy_xdp,
    bench_get_time_heavy,
    get_time_heavy_input_value,
    GET_TIME_HEAVY_INPUT_SIZE)
