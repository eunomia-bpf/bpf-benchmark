#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, int);
    __type(value, int);
} tv_map SEC(".maps");

SEC("xdp") int tv_proof_helper(struct xdp_md *ctx)
{
    (void)ctx;
    (void)bpf_get_prandom_u32();
    return 2;
}

SEC("xdp") int tv_proof_map(struct xdp_md *ctx)
{
    int key = 0;
    (void)ctx;
    int *value = bpf_map_lookup_elem(&tv_map, &key);
    return value ? *value : 0;
}

char LICENSE[] SEC("license") = "GPL";

static volatile int private_zero;
SEC("xdp") int tv_proof_private(struct xdp_md *ctx)
{
    (void)ctx;
    return private_zero == 0 ? 2 : 0;
}
