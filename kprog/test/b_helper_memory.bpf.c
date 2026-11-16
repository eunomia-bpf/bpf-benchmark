/* Detect lost helper writes, discarded key reads and false disjointness. */
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, __u64);
} values SEC(".maps");

union x86_sim_stack_mem { __u64 words[4]; };

SEC("tc")
unsigned spill_values(struct __sk_buff *context)
{
    volatile union x86_sim_stack_mem arena;
    arena.words[0] = 0;
    arena.words[1] = 0xdeadbeef;
    arena.words[2] = context->mark;
    arena.words[3] = 0x12345678;
    __u64 *value = bpf_map_lookup_elem(&values, (const void *)&arena.words[0]);
    if (!value)
        return 0;
    *value = (__u32)(context->priority + 12345);
    if (bpf_probe_read_kernel((void *)&arena.words[1], 8, value))
        return 1;
    /* An invalid userspace source must zero destination even on failure. */
    if (bpf_probe_read_user((void *)&arena.words[3], 8, (const void *)1) >= 0)
        return 2;
    /* The source and destination may alias: readonly is per argument. */
    if (bpf_probe_read_kernel(value, 8, value))
        return 3;
    return (__u32)arena.words[2] ^ (__u32)arena.words[1] ^
           (__u32)arena.words[3] ^ (__u32)arena.words[0];
}
char LICENSE[] SEC("license") = "GPL";
