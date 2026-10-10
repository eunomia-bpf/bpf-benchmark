#include <linux/bpf.h>
#include <linux/if_ether.h>
#include <bpf/bpf_helpers.h>

struct {
    __uint(type, BPF_MAP_TYPE_DEVMAP);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, __u32);
} katran_route SEC(".maps");

SEC("xdp/router_redirect")
int katran_router_redirect(struct xdp_md *ctx)
{
    void *data = (void *)(long)ctx->data;
    void *data_end = (void *)(long)ctx->data_end;
    struct ethhdr *eth = data;

    if ((void *)(eth + 1) > data_end)
        return XDP_DROP;

    /* rtreal0 -> real0 backend link. */
    eth->h_dest[0] = 0x02;
    eth->h_dest[1] = 0x00;
    eth->h_dest[2] = 0x00;
    eth->h_dest[3] = 0x00;
    eth->h_dest[4] = 0x00;
    eth->h_dest[5] = 0x2c;
    eth->h_source[0] = 0x02;
    eth->h_source[1] = 0x00;
    eth->h_source[2] = 0x00;
    eth->h_source[3] = 0x00;
    eth->h_source[4] = 0x00;
    eth->h_source[5] = 0x2b;
    return bpf_redirect_map(&katran_route, 0, XDP_DROP);
}

SEC("xdp/receiver_sink")
int katran_receiver_sink(struct xdp_md *ctx)
{
    (void)ctx;
    return XDP_DROP;
}

char LICENSE[] SEC("license") = "GPL";
