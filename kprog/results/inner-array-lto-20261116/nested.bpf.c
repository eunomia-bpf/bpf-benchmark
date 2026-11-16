#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
struct inner_definition {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 5);
    __type(key, __u32);
    __type(value, __u32);
};
struct {
    __uint(type, BPF_MAP_TYPE_HASH_OF_MAPS);
    __uint(max_entries, 16);
    __type(key, __u32);
    __array(values, struct inner_definition);
} outer SEC(".maps");
SEC("socket") int entry(void *ctx)
{
    __u32 key=0;
    void *inner=bpf_map_lookup_elem(&outer,&key);
    return inner ? bpf_map_lookup_elem(inner,&key) != 0 : 0;
}
char LICENSE[] SEC("license")="GPL";
