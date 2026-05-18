/*
 * Stage 2 POC: smallest possible program that exercises a BPF helper.
 *
 * Calls bpf_ktime_get_ns() once and writes the result to data[0..8].
 * Both runtimes (kernel_jit and native_lab) should write a non-zero
 * timestamp. The timestamps won't be bit-identical across runs (clock
 * advances), so the smoke test asserts `result != 0` rather than
 * equality.
 */
#include "include/native_helpers.h"

SEC("xdp") int helper_only_ktime(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 8 > data_end) {
        return XDP_ABORTED;
    }

    u64 now = bpf_ktime_get_ns();
    micro_write_u64_le(data, now);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
