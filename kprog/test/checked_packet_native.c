// Native input uses the sole target's actual kernel contexts, not UAPI layouts.
#define BPF_NO_PRESERVE_ACCESS_INDEX
#include "vmlinux.h"
int packet_xdp(struct xdp_buff *ctx)
{
    unsigned char *data=ctx->data, *end=ctx->data_end;
    if (end-data<64) return 1;
    return data[0]==0x5a?2:1;
}
int packet_tc(struct sk_buff *ctx)
{
    struct qdisc_skb_cb *qdisc=(void *)ctx->cb;
    unsigned *metadata=(void *)qdisc->data;
    metadata[0]+=ctx->mark;
    ctx->mark^=ctx->priority;
    ctx->priority+=3;
    return metadata[0]&1?0:2;
}
