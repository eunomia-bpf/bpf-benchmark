/*
 * Stage 2 test: PERCPU_HASH per-key counter (lookup, write-back).
 *
 * Real-world shape: lock-free per-cpu counter table for high-rate
 * events (cilium nodeport-stats, tetragon event-rate). The BPF JIT
 * inlines PERCPU_HASH `bpf_map_lookup_elem` via
 * `htab_lru_percpu_map_gen_lookup` on recent kernels -- different
 * inline shape from regular HASH so this is a separate test point.
 * Our current native-link inline path only covers HASH; PERCPU_HASH
 * falls back to a regular helper call.
 *
 * Maps: 1 (PERCPU_HASH).   Inline-eligible: no (PERCPU_HASH != HASH).
 */
#include "include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_PERCPU_HASH);
    __uint(max_entries, 256);
    __type(key, __u32);
    __type(value, __u64);
} cnt_pcpu SEC(".maps");

SEC("xdp") int map_percpu_hash_counter(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 8 > data_end) {
        return XDP_ABORTED;
    }

    __u32 key = 7;
    __u64 zero = 0;
    bpf_map_update_elem(&cnt_pcpu, &key, &zero, 0);

    __u64 *got = bpf_map_lookup_elem(&cnt_pcpu, &key);
    __u64 out = 0;
    if (got) {
        *got += 1;
        out = *got;
    }
    micro_write_u64_le(data, out);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
