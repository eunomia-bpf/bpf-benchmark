#include "common.h"

#define MAP_LOOKUP_REPEAT_ROUNDS 256U
#define MAP_LOOKUP_REPEAT_SLOTS 8U
#define MAP_LOOKUP_REPEAT_INPUT_SIZE (8U + MAP_LOOKUP_REPEAT_SLOTS * 8U)

struct map_lookup_repeat_input_value {
    unsigned char data[MAP_LOOKUP_REPEAT_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct map_lookup_repeat_input_value);
} input_map SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, MAP_LOOKUP_REPEAT_SLOTS);
    __type(key, __u32);
    __type(value, __u64);
} lookup_map SEC(".maps");

static __always_inline int
populate_map_lookup_repeat(const u8 *data, u32 len)
{
    if (!micro_has_bytes(len, 8U, MAP_LOOKUP_REPEAT_SLOTS * 8U)) {
        return -1;
    }

    for (u32 slot = 0; slot < MAP_LOOKUP_REPEAT_SLOTS; slot++) {
        __u32 key = slot;
        u64 value = micro_read_u64_le(data, 8U + slot * 8U) ^
                    ((u64)(slot + 1U) * 0x9E3779B97F4A7C15ULL);
        if (bpf_map_update_elem(&lookup_map, &key, &value, BPF_ANY) != 0) {
            return -1;
        }
    }

    return 0;
}

static __always_inline int
bench_map_lookup_repeat(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8U)) {
        return -1;
    }

    u32 rounds = micro_read_u32_le(data, 0U);
    u32 slots = micro_read_u32_le(data, 4U);
    if (rounds != MAP_LOOKUP_REPEAT_ROUNDS || slots != MAP_LOOKUP_REPEAT_SLOTS) {
        return -1;
    }
    if (populate_map_lookup_repeat(data, len) < 0) {
        return -1;
    }

    u64 acc = 0x243F6A8885A308D3ULL;
    for (u32 index = 0; index < MAP_LOOKUP_REPEAT_ROUNDS; index++) {
        __u32 hot_key = (index * 3U) & (MAP_LOOKUP_REPEAT_SLOTS - 1U);
        __u32 cold_key = (hot_key + 5U) & (MAP_LOOKUP_REPEAT_SLOTS - 1U);
        u64 *first = bpf_map_lookup_elem(&lookup_map, &hot_key);
        u64 *second;

        if (!first) {
            return -1;
        }
        acc += *first + index;

        second = bpf_map_lookup_elem(&lookup_map, &hot_key);
        if (!second) {
            return -1;
        }
        acc ^= *second << (index & 7U);

        if ((index & 3U) == 0U) {
            u64 *third = bpf_map_lookup_elem(&lookup_map, &cold_key);
            if (!third) {
                return -1;
            }
            acc += *third >> ((index >> 2U) & 7U);
        }

        acc = micro_rotl64(acc, (index & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    map_lookup_repeat_xdp,
    bench_map_lookup_repeat,
    map_lookup_repeat_input_value,
    MAP_LOOKUP_REPEAT_INPUT_SIZE)
