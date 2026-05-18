/*
 * Stage 2 POC: realistic mini program using a helper + a map together.
 *
 *   key  = bpf_get_smp_processor_id()
 *   tag  = bpf_get_current_uid_gid()      // deterministic across runtimes
 *   map[key] = tag
 *   read map[key] back, write to packet
 *
 * Per-cpu tagging shape: per-cpu slot keyed by smp_id, value derived
 * from a process-identity helper. `bpf_get_current_uid_gid()` is
 * chosen over `bpf_ktime_get_ns()` so the stored value is bit-
 * identical between the native_lab and kernel TEST_RUN calls (both
 * run as root), making result-equality a real invariant rather than
 * a near-miss-with-tolerance.
 */
#include "include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_PERCPU_ARRAY);
    __uint(max_entries, 64);
    __type(key, __u32);
    __type(value, __u64);
} cpu_ts SEC(".maps");

SEC("xdp") int combined_helper_map(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 8 > data_end) {
        return XDP_ABORTED;
    }

    __u32 cpu = bpf_get_smp_processor_id();
    __u64 tag = bpf_get_current_uid_gid();
    bpf_map_update_elem(&cpu_ts, &cpu, &tag, 0);

    __u64 *got = bpf_map_lookup_elem(&cpu_ts, &cpu);
    __u64 out = got ? *got : 0;
    micro_write_u64_le(data, out);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
