/*
 * Stage 2 POC: BPF_MAP_TYPE_HASH with write + lookup.
 *
 * Same shape as map_array_lookup but on a HASH map. The BPF JIT does
 * NOT inline bpf_map_lookup_elem for HASH maps (RCU + hash chain walk),
 * so native_lab and BPF JIT should perform roughly the same here.
 */
#include "include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 8);
    __type(key, __u32);
    __type(value, __u64);
} test_hash SEC(".maps");

SEC("xdp") int map_hash_lookup(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 8 > data_end) {
        return XDP_ABORTED;
    }

    __u32 key = 7;
    __u64 value = 0x1122334455667788ULL;
    bpf_map_update_elem(&test_hash, &key, &value, 0 /* BPF_ANY */);

    __u64 *got = bpf_map_lookup_elem(&test_hash, &key);
    __u64 out = got ? *got : 0;
    micro_write_u64_le(data, out);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
