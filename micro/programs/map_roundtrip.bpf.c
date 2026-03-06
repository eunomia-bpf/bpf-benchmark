#include "common.h"

#define MAP_ROUNDTRIP_ROUNDS 64U
#define MAP_ROUNDTRIP_INPUT_SIZE 16U

struct map_roundtrip_input_value {
    unsigned char data[MAP_ROUNDTRIP_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct map_roundtrip_input_value);
} input_map SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, __u64);
} scratch_map SEC(".maps");

static __always_inline int bench_map_roundtrip(const u8 *data, u32 len, u64 *out)
{
    __u32 key = 0;

    if (!micro_has_bytes(len, 0, MAP_ROUNDTRIP_INPUT_SIZE)) {
        return -1;
    }

    u32 rounds = micro_read_u32_le(data, 0);
    u32 mix = micro_read_u32_le(data, 4);
    u64 seed = micro_read_u64_le(data, 8);

    if (rounds != MAP_ROUNDTRIP_ROUNDS) {
        return -1;
    }

    u64 acc = seed;
    for (u32 i = 0; i < MAP_ROUNDTRIP_ROUNDS; i++) {
        u64 value = acc ^ ((u64)mix << (i & 7U)) ^ (0x9E3779B97F4A7C15ULL + i);
        u64 *slot;

        if (bpf_map_update_elem(&scratch_map, &key, &value, BPF_ANY) != 0) {
            return -1;
        }
        slot = bpf_map_lookup_elem(&scratch_map, &key);
        if (!slot) {
            return -1;
        }
        acc = (*slot + (acc << 1) + i) ^ (value >> (i & 7U));
    }

    *out = acc;
    return 0;
}

DEFINE_MAP_BACKED_XDP_BENCH(
    map_roundtrip_xdp,
    bench_map_roundtrip,
    map_roundtrip_input_value,
    MAP_ROUNDTRIP_INPUT_SIZE)
