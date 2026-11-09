#include <linux/bpf.h>
#include <bpf_helpers.h>
struct { __uint(type, BPF_MAP_TYPE_ARRAY); __uint(max_entries, 1); __type(key, __u32); __type(value, __u64); } tail_counter SEC(".maps");
struct { __uint(type, BPF_MAP_TYPE_PROG_ARRAY); __uint(max_entries, 1); __type(key, __u32); __type(value, __u32); } tail_jumps SEC(".maps");
SEC("classifier") int entry(void *ctx)
{
    volatile __u64 stack[8];
    __u32 key = 0;
    stack[7] = 7;
    __u64 *count = bpf_map_lookup_elem(&tail_counter, &key);
    if (count) {
        (*count)++;
        bpf_tail_call(ctx, &tail_jumps, 0);
    }
    return stack[7] == 7 ? 2 : 0;
}
char LICENSE[] SEC("license") = "GPL";
