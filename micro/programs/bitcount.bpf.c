#include "common.h"

#define BITCOUNT_MAX_COUNT 256U
#define BITCOUNT_INPUT_SIZE (8U + BITCOUNT_MAX_COUNT * 8U)

struct bitcount_input_value {
    unsigned char data[BITCOUNT_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct bitcount_input_value);
} input_map SEC(".maps");

static __always_inline u64 micro_popcount64(u64 value)
{
    u64 count = 0;
    for (u32 bit = 0; bit < 64 && value != 0; bit++) {
        value &= value - 1;
        count++;
    }
    return count;
}

static __always_inline int bench_bitcount(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 seed = micro_read_u32_le(data, 4);

    if (count != BITCOUNT_MAX_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, BITCOUNT_MAX_COUNT * 8U)) {
        return -1;
    }

    u64 acc = seed;
    for (u32 i = 0; i < BITCOUNT_MAX_COUNT; i++) {
        u64 value = micro_read_u64_le(data, 8 + i * 8);
        acc += micro_popcount64(value ^ acc);
        acc ^= value >> (i & 7);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(bitcount_xdp, bench_bitcount, bitcount_input_value, BITCOUNT_INPUT_SIZE)
