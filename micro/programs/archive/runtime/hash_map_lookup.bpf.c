#include "common.h"

#define HASH_MAP_LOOKUP_KEYS 64U
#define HASH_MAP_LOOKUP_INPUT_SIZE (HASH_MAP_LOOKUP_KEYS * 4U)
#define HASH_MAP_LOOKUP_SENTINEL_KEY 0xFFFFFFFFU

struct hash_map_lookup_input_value {
    unsigned char data[HASH_MAP_LOOKUP_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct hash_map_lookup_input_value);
} input_map SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, HASH_MAP_LOOKUP_KEYS + 1U);
    __type(key, __u32);
    __type(value, __u64);
} hash_map SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, __u64);
} result_map SEC(".maps");

static __always_inline u64 hash_map_lookup_seed_value(u32 key, u32 index)
{
    return ((u64)key * 0x9E3779B185EBCA87ULL) ^
           ((u64)(index + 1U) * 0xD1342543DE82EF95ULL);
}

static __always_inline int populate_hash_map_lookup(const u8 *data, u32 len)
{
    __u32 sentinel_key = HASH_MAP_LOOKUP_SENTINEL_KEY;

    if (!micro_has_bytes(len, 0, HASH_MAP_LOOKUP_INPUT_SIZE)) {
        return -1;
    }

    if (!bpf_map_lookup_elem(&hash_map, &sentinel_key)) {
        u64 marker = 1;

        for (u32 i = 0; i < HASH_MAP_LOOKUP_KEYS; i++) {
            u32 lookup_key = micro_read_u32_le(data, i * 4U);
            u64 value = hash_map_lookup_seed_value(lookup_key, i);

            if (bpf_map_update_elem(&hash_map, &lookup_key, &value, BPF_ANY) != 0) {
                return -1;
            }
        }

        if (bpf_map_update_elem(&hash_map, &sentinel_key, &marker, BPF_ANY) != 0) {
            return -1;
        }
    }

    return 0;
}

static __always_inline int bench_hash_map_lookup(const u8 *data, u32 len, u64 *out)
{
    u64 acc = 0;

    if (!micro_has_bytes(len, 0, HASH_MAP_LOOKUP_INPUT_SIZE)) {
        return -1;
    }

    for (u32 i = 0; i < HASH_MAP_LOOKUP_KEYS; i++) {
        u32 lookup_key = micro_read_u32_le(data, i * 4U);
        u64 *value = bpf_map_lookup_elem(&hash_map, &lookup_key);

        if (value) {
            acc += *value;
        }
    }

    *out = acc;
    return 0;
}

SEC("xdp") int hash_map_lookup_xdp(struct xdp_md *ctx)
{
    struct hash_map_lookup_input_value *input;
    u64 result = 0;
    __u32 key = 0;

    (void)ctx;
    input = bpf_map_lookup_elem(&input_map, &key);
    if (!input) {
        return XDP_ABORTED;
    }
    if (populate_hash_map_lookup(input->data, HASH_MAP_LOOKUP_INPUT_SIZE) < 0) {
        return XDP_ABORTED;
    }
    if (bench_hash_map_lookup(input->data, HASH_MAP_LOOKUP_INPUT_SIZE, &result) < 0) {
        return XDP_ABORTED;
    }
    bpf_map_update_elem(&result_map, &key, &result, BPF_ANY);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
