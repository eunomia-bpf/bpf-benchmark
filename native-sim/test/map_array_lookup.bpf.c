/*
 * Stage 2 POC: BPF_MAP_TYPE_ARRAY with write + lookup.
 *
 * The program writes a deterministic value at key=0 and then reads it
 * back via bpf_map_lookup_elem. Both runtimes must yield identical
 * results.
 *
 * BPF JIT inlines bpf_map_lookup_elem for ARRAY maps -- replaces the
 * call with direct pointer math against map->data. native_lab will
 * still emit a real call, so this is one of the cases where BPF JIT
 * is expected to be faster than native_lab.
 */
#include "include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 4);
    __type(key, __u32);
    __type(value, __u64);
} test_array SEC(".maps");

SEC("xdp") int map_array_lookup(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 8 > data_end) {
        return XDP_ABORTED;
    }

    __u32 key = 0;
    __u64 value = 0xDEADBEEFCAFE0001ULL;
    bpf_map_update_elem(&test_array, &key, &value, 0 /* BPF_ANY */);

    __u64 *got = bpf_map_lookup_elem(&test_array, &key);
    __u64 out = got ? *got : 0;
    micro_write_u64_le(data, out);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
