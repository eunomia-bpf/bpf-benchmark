/*
 * Stage 2 POC: smallest deterministic single-helper program.
 *
 * Calls bpf_get_current_uid_gid() once and writes the result to
 * data[0..8]. Both runtimes run inside the same uid (root, via the
 * micro suite's `sudo: true`), so the value is bit-identical between
 * native_lab and kernel and can be verified by exact-equality
 * comparison -- unlike ktime / pid_tgid baselines which advance or
 * differ between the two TEST_RUN call sites.
 */
#include "include/native_helpers.h"

SEC("xdp") int helper_only_uid_gid(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 8 > data_end) {
        return XDP_ABORTED;
    }

    u64 v = bpf_get_current_uid_gid();
    micro_write_u64_le(data, v);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
