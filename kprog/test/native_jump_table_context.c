/* A real single-context KPROBE ABI, shared by BPF and direct-x86 builds. */
#if defined(__bpf__) || defined(__BPF__)
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#define ENTRY SEC("kprobe/jump_table")
char LICENSE[] SEC("license") = "GPL";
#else
#define ENTRY
#endif

ENTRY int jump_table(const volatile unsigned long *ctx)
{
    unsigned int index = (unsigned int)ctx[10] & 15;
    switch (index) {
    case 0: return ctx[0] + 17;
    case 1: return ctx[1] * 3;
    case 2: return ctx[2] ^ 0x1234;
    case 3: return ctx[3] - 29;
    case 4: return ctx[4] | 0x8000;
    case 5: return ctx[5] & 0x7fff;
    case 6: return ctx[6] + 71;
    case 7: return ctx[7] * 5;
    default: return 0;
    }
}
