#include <bpf/ctx/xdp.h>

__attribute__((noinline)) unsigned native_ifindex(const struct xdp_md *ctx)
{
    return ctx_get_ifindex(ctx);
}
__attribute__((noinline)) unsigned native_ingress(const struct xdp_md *ctx)
{
    return ctx_get_ingress_ifindex(ctx);
}
