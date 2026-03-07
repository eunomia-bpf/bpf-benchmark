#include "common.h"

#define PERCPU_MAP_UPDATE_PAIRS 32U
#define PERCPU_MAP_UPDATE_INPUT_SIZE (PERCPU_MAP_UPDATE_PAIRS * 12U)

struct percpu_map_update_input_value {
    unsigned char data[PERCPU_MAP_UPDATE_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct percpu_map_update_input_value);
} input_map SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_PERCPU_ARRAY);
    __uint(max_entries, PERCPU_MAP_UPDATE_PAIRS);
    __type(key, __u32);
    __type(value, __u64);
} percpu_map SEC(".maps");

static __always_inline int bench_percpu_map_update(const u8 *data, u32 len, u64 *out)
{
    u64 acc = 0;

    if (!micro_has_bytes(len, 0, PERCPU_MAP_UPDATE_INPUT_SIZE)) {
        return -1;
    }

    for (u32 i = 0; i < PERCPU_MAP_UPDATE_PAIRS; i++) {
        u32 key = micro_read_u32_le(data, i * 12U);
        u64 value = micro_read_u64_le(data, i * 12U + 4U);

        if (key >= PERCPU_MAP_UPDATE_PAIRS) {
            return -1;
        }
        if (bpf_map_update_elem(&percpu_map, &key, &value, BPF_ANY) != 0) {
            return -1;
        }

        acc ^= value + ((u64)key << (i & 7U));
        acc = micro_rotl64(acc, (i & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_MAP_BACKED_XDP_BENCH(
    percpu_map_update_xdp,
    bench_percpu_map_update,
    percpu_map_update_input_value,
    PERCPU_MAP_UPDATE_INPUT_SIZE)
