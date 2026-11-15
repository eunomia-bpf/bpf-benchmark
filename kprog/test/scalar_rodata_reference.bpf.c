#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
SEC("kprobe/scalar_data")
unsigned scalar_reference(const volatile unsigned long *context)
{
    return 0x12340000U + ((context[0] & 7) + 1) * 0x101U;
}
char LICENSE[] SEC("license") = "GPL";
