/*
 * Stage 2 POC: BPF_MAP_TYPE_PERCPU_ARRAY.
 *
 * Tests per-CPU map semantics: each CPU has its own copy of value[key].
 * Write + read happen on the same CPU in the same prog invocation, so
 * the read sees what was just written (regardless of preemption).
 */
#include "include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_PERCPU_ARRAY);
    __uint(max_entries, 4);
    __type(key, __u32);
    __type(value, __u64);
} test_percpu SEC(".maps");

SEC("xdp") int map_percpu_array(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 8 > data_end) {
        return XDP_ABORTED;
    }

    __u32 key = 2;
    __u64 value = 0xFEEDFACECAFEBABEULL;
    bpf_map_update_elem(&test_percpu, &key, &value, 0);

    __u64 *got = bpf_map_lookup_elem(&test_percpu, &key);
    __u64 out = got ? *got : 0;
    micro_write_u64_le(data, out);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
