// Public accesses use the same unmodified UAPI header as upstream Cilium.
#include <linux/bpf.h>
#define SEC(S) __attribute__((section(S),used))
extern unsigned long observe_context(void *);
SEC("cgroup/connect4") int socket4(struct bpf_sock_addr *ctx)
{
    if (observe_context(ctx)!=63 || ctx->user_family!=2 || ctx->family!=2 ||
        ctx->type!=1 || ctx->protocol!=6 || ctx->user_ip4!=0x04030201 || ctx->user_port!=0x3412)
        return 1;
    if (!ctx->sk || ctx->sk->family!=2 || ctx->sk->src_port!=1234) return 2;
    ctx->user_ip4=0x08070605;
    ctx->user_port=0xfeedbeef;
    ctx->msg_src_ip4=0x12345678;
    return 0;
}
SEC("cgroup/connect6") int socket6(struct bpf_sock_addr *ctx)
{
    if (observe_context(ctx)!=63 || ctx->user_family!=10 || ctx->family!=10 ||
        ctx->protocol!=17 || ctx->user_ip6[0]!=0x11111111 || ctx->user_ip6[3]!=0x44444444)
        return 1;
    ctx->user_ip6[1]=0x12345678;
    ctx->msg_src_ip6[3]=0x87654321;
    return 0;
}
SEC("cgroup/sock") int socket_direct(struct bpf_sock *ctx)
{
    if (observe_context(ctx)!=63 || ctx->family!=2 || ctx->type!=1 || ctx->protocol!=6 ||
        ctx->src_port!=1234 || ctx->dst_port!=0x3412 || ctx->state!=7) return 1;
    ctx->bound_dev_if=47; ctx->mark=53; ctx->priority=59;
    return 0;
}
SEC("cgroup/sendmsg4") void socket_store_only(struct bpf_sock_addr *ctx)
{
    ctx->user_ip4=0x55555555;
}
