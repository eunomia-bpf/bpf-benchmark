/*
 * Stage 2 test: most-complex case -- 3 helpers + 2 maps of different
 * inline classes (HASH + PERCPU_HASH).
 *
 * Real-world shape: a tetragon/tracee-style stats aggregator that
 * tags each observation with (pid_tgid mod K) into a HASH bucket
 * for cross-cpu aggregation and bumps a PERCPU_HASH per-cpu rate
 * counter at the same time.
 *
 * Multi-map (HASH + PERCPU_HASH) so native-link inline is disabled;
 * both lookups go through plain `bpf_map_lookup_elem`. Stored tag is
 * `bpf_get_current_uid_gid()` (deterministic across runtimes, both
 * run as root) rather than `bpf_ktime_get_ns()` (advances between
 * the two TEST_RUN calls), so the XOR of the two re-reads is a
 * stable, bit-identical value `uid_gid ^ 1` across native_lab and
 * kernel runs even though pid_tgid and smp_id route them to
 * different bucket slots.
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
    __u64 tag    = bpf_get_current_uid_gid();

    bpf_map_update_elem(&stats_h, &bucket, &tag, 0);
    __u64 one = 1;
    bpf_map_update_elem(&rate_pcpu, &cpu, &one, 0);

    __u64 *h = bpf_map_lookup_elem(&stats_h, &bucket);
    __u64 *p = bpf_map_lookup_elem(&rate_pcpu, &cpu);
    __u64 out = (h ? *h : 0) ^ (p ? *p : 0);
    micro_write_u64_le(data, out);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
