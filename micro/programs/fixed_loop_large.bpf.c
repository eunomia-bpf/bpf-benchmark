#include "common.h"

#define FIXED_LOOP_LARGE_INPUT_SIZE 16U
#define FIXED_LOOP_LARGE_ROUNDS 1024U

struct fixed_loop_large_input_value {
    unsigned char data[FIXED_LOOP_LARGE_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct fixed_loop_large_input_value);
} input_map SEC(".maps");

static __always_inline int bench_fixed_loop_large(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, FIXED_LOOP_LARGE_INPUT_SIZE)) {
        return -1;
    }

    u32 rounds = micro_read_u32_le(data, 0);
    u32 mix = micro_read_u32_le(data, 4);
    u64 seed = micro_read_u64_le(data, 8);
    if (rounds != FIXED_LOOP_LARGE_ROUNDS) {
        return -1;
    }

    u64 state = seed ^ ((u64)mix << 17);
    u64 acc = seed + mix;
    for (u32 i = 0; i < FIXED_LOOP_LARGE_ROUNDS; i++) {
        state = state * 0xD1342543DE82EF95ULL + 0x9E3779B97F4A7C15ULL + i;
        acc ^= state + (acc << 2);
        acc = (acc << 7) | (acc >> 57);
    }

    *out = acc ^ state;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    fixed_loop_large_xdp,
    bench_fixed_loop_large,
    fixed_loop_large_input_value,
    FIXED_LOOP_LARGE_INPUT_SIZE)
