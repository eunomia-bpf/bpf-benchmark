/*
 * Stage 2 POC: bpf_get_current_pid_tgid helper.
 *
 * Returns the calling process's (tgid << 32) | pid. Under
 * BPF_PROG_TEST_RUN the calling process is the test driver, so both
 * runtimes should see the SAME pid_tgid value -> result identity check
 * can be strict equality (modulo task migration races, which are rare
 * under a single-CPU pinned run).
 */
#include "include/native_helpers.h"

SEC("xdp") int helper_get_pid_tgid(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 8 > data_end) {
        return XDP_ABORTED;
    }

    u64 pid_tgid = bpf_get_current_pid_tgid();
    micro_write_u64_le(data, pid_tgid);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
