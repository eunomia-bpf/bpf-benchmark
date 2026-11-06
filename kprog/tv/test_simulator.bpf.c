#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, int);
    __type(value, int);
} tv_map SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 1);
    __type(key, int);
    __type(value, int);
} tv_hash_map SEC(".maps");

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

SEC("xdp") int tv_proof_hash(struct xdp_md *ctx)
{
    int key = 0;
    (void)ctx;
    int *value = bpf_map_lookup_elem(&tv_hash_map, &key);
    return value ? *value : 0;
}

char LICENSE[] SEC("license") = "GPL";

static volatile int private_zero;
SEC("xdp") int tv_proof_private(struct xdp_md *ctx)
{
    (void)ctx;
    return private_zero == 0 ? 2 : 0;
}

#ifndef TV_READONLY_WORD
#define TV_READONLY_WORD 0x1122334400000002ULL
#endif
static const __u64 tv_readonly_data[2] = {TV_READONLY_WORD, 0xaabbccdd00000000ULL};
SEC("xdp") int tv_proof_readonly(struct xdp_md *ctx)
{
    (void)ctx;
    const volatile __u64 *data = tv_readonly_data;
    return (__u32)(data[0] + data[1]);
}
