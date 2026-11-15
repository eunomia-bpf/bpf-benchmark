/* Functional reference for the scheduled-table fixture's observable result. */
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
SEC("kprobe/scheduled")
unsigned int scheduled_table(const volatile unsigned int *context)
{
    unsigned int index = context[0] & 7;
    return index < 4 ? (index + 1) * 10 + 10 : 0;
}
char LICENSE[] SEC("license") = "GPL";
