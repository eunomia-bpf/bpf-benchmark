#include "common.h"

#define SMALLMUL_STRENGTH_REDUCE_COUNT 128U
#define SMALLMUL_STRENGTH_REDUCE_INPUT_SIZE \
    (8U + SMALLMUL_STRENGTH_REDUCE_COUNT * 8U)

struct smallmul_strength_reduce_input_value {
    unsigned char data[SMALLMUL_STRENGTH_REDUCE_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct smallmul_strength_reduce_input_value);
} input_map SEC(".maps");

static __always_inline int
bench_smallmul_strength_reduce(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8U)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0U);
    u32 seed = micro_read_u32_le(data, 4U);
    if (count != SMALLMUL_STRENGTH_REDUCE_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8U, SMALLMUL_STRENGTH_REDUCE_COUNT * 8U)) {
        return -1;
    }

    u64 acc = ((u64)seed << 32U) ^ 0xE7037ED1A0B428DBULL;
    for (u32 index = 0; index < SMALLMUL_STRENGTH_REDUCE_COUNT; index++) {
        u64 value = micro_read_u64_le(data, 8U + index * 8U);
        u64 mix0 = value * 3U + acc;
        u64 mix1 = value * 5U + ((u64)index * 9U);
        u64 mix2 = value * 7U + ((u64)index * 33U) + ((u64)seed * 3U);

        acc += mix0 ^ (mix1 << (index & 3U));
        acc ^= mix2 + ((u64)index * 24U);
        acc += (value * 15U) ^ ((u64)index * 5U);
        acc = micro_rotl64(acc, (index & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    smallmul_strength_reduce_xdp,
    bench_smallmul_strength_reduce,
    smallmul_strength_reduce_input_value,
    SMALLMUL_STRENGTH_REDUCE_INPUT_SIZE)
