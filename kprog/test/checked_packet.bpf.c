#include <linux/bpf.h>
#include <bpf_helpers.h>
SEC("xdp") int packet_xdp(struct xdp_md *ctx)
{
    unsigned char *data=(void *)(long)ctx->data, *end=(void *)(long)ctx->data_end;
    if (data+64>end) return 1;
    return data[0]==0x5a?2:1;
}
SEC("tc") int packet_tc(struct __sk_buff *ctx)
{
    ctx->cb[0]+=ctx->mark;
    ctx->mark^=ctx->priority;
    ctx->priority+=3;
    return ctx->cb[0]&1?0:2;
}
char LICENSE[] SEC("license")="GPL";
