/*
 * Stage 2 test: chain of 4 distinct deterministic helper calls.
 *
 * Exercises uid_gid + map_update + map_lookup + map_delete on a
 * single-slot HASH map. The stored value is `bpf_get_current_uid_gid()`
 * which is identical between the native_lab and kernel TEST_RUN
 * processes (both run as root), and lookup returns exactly what
 * update wrote, so result is bit-identical across runtimes -- a real
 * correctness invariant rather than a non-deterministic loose check.
 *
 * Replaces an earlier ktime/prandom-XOR chain that varied by design.
 *
 * Maps: 1 (HASH).   Helpers: 4.   Inline-eligible: yes (HASH map).
 */
#include "include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, __u64);
} chain_h SEC(".maps");

SEC("xdp") int helper_chain_simple(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 8 > data_end) {
        return XDP_ABORTED;
    }

    __u32 key = 0;
    __u64 tag = bpf_get_current_uid_gid();
    bpf_map_update_elem(&chain_h, &key, &tag, 0);
    __u64 *got = bpf_map_lookup_elem(&chain_h, &key);
    __u64 out = got ? *got : 0;
    bpf_map_delete_elem(&chain_h, &key);
    micro_write_u64_le(data, out);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
