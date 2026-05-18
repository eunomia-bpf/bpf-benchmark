/*
 * Stage 2 test: chain of pure-helper calls, no maps.
 *
 * Exercises 4 distinct helpers (ktime, pid_tgid, smp_id, uid_gid)
 * folded together with XOR. Real-world shape: a tracer that mixes
 * timestamp + identity bits into a single observation token. The
 * result is non-deterministic (ktime / pid_tgid drift across iters),
 * so the test driver only checks XDP_PASS + nonzero result.
 *
 * Maps: none.   Helpers: 4.   Inline-eligible: no (no HASH map).
 */
#include "include/native_helpers.h"

SEC("xdp") int helper_chain_simple(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 8 > data_end) {
        return XDP_ABORTED;
    }

    __u64 v = bpf_ktime_get_ns();
    v ^= bpf_get_current_pid_tgid();
    v ^= ((__u64)bpf_get_smp_processor_id() << 32);
    v ^= bpf_get_current_uid_gid();
    micro_write_u64_le(data, v);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
