// Detect qdisc overlap, wrong wire_len, and truncated/native XDP packet pointers.
#include <linux/bpf.h>
#include <stddef.h>
#define SEC(S) __attribute__((section(S),used))
#ifdef BPF_POINTER_ASM
#define TC_POINTER(ctx,field) ({ void *value; asm volatile("%0 = *(u32 *)(%1 + %2)" : "=r"(value) : "r"(ctx),"i"(offsetof(struct __sk_buff,field))); value; })
#else
#define TC_POINTER(ctx,field) ((void *)(long)(ctx)->field)
#endif
extern unsigned long observe_context(void *);
_Static_assert(sizeof(((struct __sk_buff *)0)->cb)==20,"public metadata extent");
SEC("tc/entry") int packet_tc(struct __sk_buff *ctx)
{
    if (observe_context(ctx)!=63 || ctx->cb[0]!=101 || ctx->cb[4]!=105) return 1;
    if (ctx->len!=128 || ctx->wire_len!=976 || ctx->tc_classid!=0xa1a2 ||
        ctx->ifindex!=37 || ctx->ingress_ifindex!=41 || ctx->protocol!=0x1234 ||
        ctx->vlan_present!=1 || ctx->vlan_tci!=0x5678 || ctx->vlan_proto!=0x1234 || ctx->pkt_type!=5) return 2;
    unsigned char *data=TC_POINTER(ctx,data);
    unsigned char *end=TC_POINTER(ctx,data_end);
    unsigned char *meta=TC_POINTER(ctx,data_meta);
    if (end-data!=128 || data-meta!=16 || data[73]!=0xb7) return 3;
    ctx->cb[0]=201; ctx->cb[4]=205; ctx->tc_classid=0;
    ctx->mark=53; ctx->priority=59; data[73]=0xc8;
    ctx->queue_mapping=65535;
    return sizeof(ctx->cb)+8; // XDP META_PIVOT must remain 28, not 56.
}
SEC("tc/entry") void packet_queue(struct __sk_buff *ctx,unsigned value)
{
    ctx->queue_mapping=value;
}
SEC("xdp") int packet_xdp(struct xdp_md *ctx)
{
    if (observe_context(ctx)!=63 || ctx->ingress_ifindex!=37 || ctx->rx_queue_index!=43 || ctx->egress_ifindex!=47) return 1;
    unsigned char *data=(void *)(long)ctx->data;
    unsigned char *end=(void *)(long)ctx->data_end;
    unsigned char *meta=(void *)(long)ctx->data_meta;
    if (end-data!=128 || data-meta!=16 || data[73]!=0xc8) return 2;
    data[73]=0xd9;
    return 0;
}
#ifdef BPF_POINTER_ASM
SEC("xdp") unsigned long packet_xdp_length(struct xdp_md *ctx)
{
    unsigned long length;
    asm volatile("r1 = *(u32 *)(%1 +0)\n\tr2 = *(u32 *)(%1 +4)\n\t%0 = r2\n\t%0 -= r1\n\t"
                 : "=r"(length) : "r"(ctx) : "r1","r2");
    return length;
}
SEC("xdp") int packet_xdp_bounds(struct xdp_md *ctx,unsigned long off,unsigned long len,unsigned long *address)
{
    int ret; void *from;
    asm volatile("r1 = *(u32 *)(%2 +0)\n\tr2 = *(u32 *)(%2 +4)\n\t%3 &= %5\n\tr1 += %3\n\t%1 = r1\n\tr1 += %4\n\tif r1 > r2 goto +2\n\t%0 = 0\n\tgoto +1\n\t%0 = %6\n\t"
                 : "=r"(ret),"=r"(from) : "r"(ctx),"r"(off),"ri"(len),"i"(255),"i"(-22) : "r1","r2");
    *address=(unsigned long)from;
    return ret;
}
SEC("xdp") int packet_xdp_two(struct xdp_md *ctx,unsigned long off,unsigned long *address)
{
    int ret; void *from;
    asm volatile("r1 = *(u32 *)(%2 +0)\n\tr2 = *(u32 *)(%2 +4)\n\t%3 &= %4\n\tr1 += %3\n\t%1 = r1\n\tr1 += 2\n\tif r1 > r2 goto +2\n\t%0 = 0\n\tgoto +1\n\t%0 = %5\n\t"
                 : "=r"(ret),"=r"(from) : "r"(ctx),"r"(off),"i"(255),"i"(-22) : "r1","r2");
    *address=(unsigned long)from;
    return ret;
}
#endif
