#include "common.h"

#define FIXED_LOOP_SMALL_INPUT_SIZE 16U
#define FIXED_LOOP_SMALL_ROUNDS 64U

struct fixed_loop_small_input_value {
    unsigned char data[FIXED_LOOP_SMALL_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct fixed_loop_small_input_value);
} input_map SEC(".maps");

static __always_inline int bench_fixed_loop_small(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, FIXED_LOOP_SMALL_INPUT_SIZE)) {
        return -1;
    }

    u32 rounds = micro_read_u32_le(data, 0);
    u32 mix = micro_read_u32_le(data, 4);
    u64 seed = micro_read_u64_le(data, 8);
    if (rounds != FIXED_LOOP_SMALL_ROUNDS) {
        return -1;
    }

    u64 state = seed ^ mix;
    u64 acc = mix;
    for (u32 i = 0; i < FIXED_LOOP_SMALL_ROUNDS; i++) {
        state = state * 0x5851F42D4C957F2DULL + 0x14057B7EF767814FULL + i;
        acc ^= state + (acc << 3);
        acc = (acc << 5) | (acc >> 59);
    }

    *out = acc ^ state;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    fixed_loop_small_xdp,
    bench_fixed_loop_small,
    fixed_loop_small_input_value,
    FIXED_LOOP_SMALL_INPUT_SIZE)
