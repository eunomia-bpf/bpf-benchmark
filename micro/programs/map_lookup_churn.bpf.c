#include "common.h"

#define MAP_LOOKUP_CHURN_ROUNDS 128U
#define MAP_LOOKUP_CHURN_WORDS 64U
#define MAP_LOOKUP_CHURN_INPUT_SIZE (12U + MAP_LOOKUP_CHURN_WORDS * 8U)

struct map_lookup_churn_input_value {
    unsigned char data[MAP_LOOKUP_CHURN_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct map_lookup_churn_input_value);
} input_map SEC(".maps");

static __always_inline int bench_map_lookup_churn(const u8 *data, u32 len, u64 *out)
{
    __u32 key = 0;
    u64 acc;

    if (!micro_has_bytes(len, 0, 12)) {
        return -1;
    }

    u32 rounds = micro_read_u32_le(data, 0);
    u32 stride = micro_read_u32_le(data, 4);
    u32 seed = micro_read_u32_le(data, 8);

    if (rounds != MAP_LOOKUP_CHURN_ROUNDS) {
        return -1;
    }
    if (!micro_has_bytes(len, 12, MAP_LOOKUP_CHURN_WORDS * 8U)) {
        return -1;
    }

    acc = seed;
    for (u32 i = 0; i < MAP_LOOKUP_CHURN_ROUNDS; i++) {
        struct map_lookup_churn_input_value *slot = bpf_map_lookup_elem(&input_map, &key);
        u32 index;
        u64 value;

        if (!slot) {
            return -1;
        }

        index = (i * stride) & (MAP_LOOKUP_CHURN_WORDS - 1U);
        value = micro_read_u64_le(slot->data, 12 + index * 8U);
        acc += value ^ ((u64)i << (i & 7U));
        acc = (acc << 7) | (acc >> 57);
        acc ^= value >> (i & 15U);
    }

    *out = acc;
    return 0;
}

DEFINE_MAP_BACKED_XDP_BENCH(
    map_lookup_churn_xdp,
    bench_map_lookup_churn,
    map_lookup_churn_input_value,
    MAP_LOOKUP_CHURN_INPUT_SIZE)
