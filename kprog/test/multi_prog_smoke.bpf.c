#include "include/native_helpers.h"

SEC("xdp") int multi_prog_first(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 1 > data_end) {
        return XDP_ABORTED;
    }
    data[0] ^= 0x11;
    return XDP_PASS;
}

SEC("xdp") int multi_prog_second(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 1 > data_end) {
        return XDP_ABORTED;
    }
    data[0] ^= 0x22;
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";

