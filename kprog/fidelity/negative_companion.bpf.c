#include <linux/bpf.h>
#include <bpf_helpers.h>
struct {
    __uint(type,BPF_MAP_TYPE_ARRAY);
    __uint(max_entries,1);
    __type(key,__u32);
    __type(value,__u64);
} neg_map SEC(".maps");
SEC("xdp") int neg_source(struct xdp_md *ctx)
{
    (void)ctx;
    __u32 key=0;
    return bpf_map_lookup_elem(&neg_map,&key) ? 2 : 0;
}
char LICENSE[] SEC("license")="GPL";
