#include "common.h"

#define STRUCT_FIELD_CLUSTER_RECORDS 32U

struct struct_field_cluster_record {
    __u32 tag;
    __u16 flags;
    __u16 length;
    __u64 src;
    __u64 dst;
    __u32 sport;
    __u32 dport;
};

struct struct_field_cluster_layout {
    __u32 record_count;
    __u32 record_size;
    struct struct_field_cluster_record records[STRUCT_FIELD_CLUSTER_RECORDS];
};

#define STRUCT_FIELD_CLUSTER_INPUT_SIZE sizeof(struct struct_field_cluster_layout)

struct struct_field_cluster_input_value {
    unsigned char data[STRUCT_FIELD_CLUSTER_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct struct_field_cluster_input_value);
} input_map SEC(".maps");

static __always_inline int
bench_struct_field_cluster(const u8 *data, u32 len, u64 *out)
{
    (void)len;

    const struct struct_field_cluster_layout *layout =
        (const struct struct_field_cluster_layout *)(const void *)data;
    if (layout->record_count != STRUCT_FIELD_CLUSTER_RECORDS ||
        layout->record_size != sizeof(struct struct_field_cluster_record)) {
        return -1;
    }

    u64 acc = 0x9E3779B97F4A7C15ULL;
    for (u32 index = 0; index < STRUCT_FIELD_CLUSTER_RECORDS; index++) {
        const struct struct_field_cluster_record *record = &layout->records[index];
        u64 tuple = record->src + record->dst;
        u64 ports = ((u64)record->sport << 32U) | record->dport;

        acc += tuple ^ (((u64)record->tag << 16U) | record->flags);
        if ((record->flags & 1U) != 0U) {
            acc ^= ports + record->length;
        } else {
            acc += (record->dst >> (index & 7U)) ^ ports;
        }
        acc ^= (u64)record->tag << ((index & 3U) * 8U);
        acc = micro_rotl64(acc, (record->tag & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    struct_field_cluster_xdp,
    bench_struct_field_cluster,
    struct_field_cluster_input_value,
    STRUCT_FIELD_CLUSTER_INPUT_SIZE)
