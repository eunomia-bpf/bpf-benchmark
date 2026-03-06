#include "common.h"

#define DEP_CHAIN_SHORT_COUNT 64U
#define DEP_CHAIN_SHORT_INPUT_SIZE (8U + DEP_CHAIN_SHORT_COUNT * 8U)

struct dep_chain_short_input_value {
    unsigned char data[DEP_CHAIN_SHORT_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct dep_chain_short_input_value);
} input_map SEC(".maps");

static __always_inline int bench_dep_chain_short(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 seed = micro_read_u32_le(data, 4);
    if (count != DEP_CHAIN_SHORT_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, DEP_CHAIN_SHORT_COUNT * 8U)) {
        return -1;
    }

    u64 acc = (u64)seed ^ 0x9E3779B97F4A7C15ULL;
    for (u32 i = 0; i < DEP_CHAIN_SHORT_COUNT; i++) {
        u64 value = micro_read_u64_le(data, 8 + i * 8U);
        acc += value ^ (acc >> 7) ^ ((u64)i << (i & 31U));
        acc ^= acc << 11;
        acc += value >> (i & 15U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    dep_chain_short_xdp,
    bench_dep_chain_short,
    dep_chain_short_input_value,
    DEP_CHAIN_SHORT_INPUT_SIZE)
