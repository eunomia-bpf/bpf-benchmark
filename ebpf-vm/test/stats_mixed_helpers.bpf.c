/*
 * Stage 2 test: most-complex case -- 3 helpers + 2 maps of different
 * inline classes (HASH + PERCPU_HASH).
 *
 * Real-world shape: a tetragon/tracee-style stats aggregator that
 * tags each observation with (pid_tgid mod K) into a HASH bucket
 * for cross-cpu aggregation and bumps a PERCPU_HASH per-cpu rate
 * counter at the same time. Mixes deterministic and helper-derived
 * inputs.
 *
 * Multi-map (HASH + PERCPU_HASH) so native-link inline is disabled;
 * both lookups go through plain `bpf_map_lookup_elem`. Result depends
 * on `bpf_ktime_get_ns()` -> non-deterministic; loose check.
 *
 * Maps: 2 (HASH + PERCPU_HASH).   Helpers: 3.
 * Inline-eligible: no (multi-map).
 */
#include "include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 64);
    __type(key, __u32);
    __type(value, __u64);
} stats_h SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_PERCPU_HASH);
    __uint(max_entries, 64);
    __type(key, __u32);
    __type(value, __u64);
} rate_pcpu SEC(".maps");

SEC("xdp") int stats_mixed_helpers(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 8 > data_end) {
        return XDP_ABORTED;
    }

    __u32 bucket = (__u32)(bpf_get_current_pid_tgid() & 0x3F);
    __u32 cpu    = bpf_get_smp_processor_id() & 0x3F;
    __u64 ts     = bpf_ktime_get_ns();

    bpf_map_update_elem(&stats_h, &bucket, &ts, 0);
    __u64 one = 1;
    bpf_map_update_elem(&rate_pcpu, &cpu, &one, 0);

    __u64 *h = bpf_map_lookup_elem(&stats_h, &bucket);
    __u64 *p = bpf_map_lookup_elem(&rate_pcpu, &cpu);
    __u64 out = (h ? *h : 0) ^ (p ? *p : 0);
    micro_write_u64_le(data, out);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
