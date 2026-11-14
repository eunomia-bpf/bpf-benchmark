#include <linux/bpf.h>
#include <bpf_helpers.h>
struct { __uint(type, BPF_MAP_TYPE_ARRAY); __uint(max_entries, 1); __type(key, __u32); __type(value, __u64); } logical SEC(".maps");
struct { __uint(type, BPF_MAP_TYPE_ARRAY); __uint(max_entries, 1); __type(key, __u32); __type(value, __u64); } other SEC(".maps");
__attribute__((noinline)) int shared(void)
{
    __u32 key = 0;
    __u64 *value = bpf_map_lookup_elem(&logical, &key);
    return value ? *value : 0;
}
SEC("socket") int entry(void *ctx)
{
    __u32 key = 0;
    __u64 *value = bpf_map_lookup_elem(&logical, &key);
    return (value ? *value : 0) + shared();
}
SEC("socket/other") int other_entry(void *ctx)
{
    __u32 key = 0;
    __u64 *value = bpf_map_lookup_elem(&other, &key);
    return value ? *value : 0;
}
extern int generated(void);
SEC("socket/dynamic") int dynamic_entry(void *ctx) { return shared() + generated(); }
char LICENSE[] SEC("license") = "GPL";
