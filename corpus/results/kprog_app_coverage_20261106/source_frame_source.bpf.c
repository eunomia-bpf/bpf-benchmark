#include <linux/bpf.h>
#include <bpf_helpers.h>
SEC("tracepoint/native/startup") __attribute__((naked))
int frame_source(void *ctx)
{
    asm volatile("r1 = r10; r1 += -8; r2 = 8; r3 = 0; call 113; exit;");
}
char LICENSE[] SEC("license") = "GPL";
