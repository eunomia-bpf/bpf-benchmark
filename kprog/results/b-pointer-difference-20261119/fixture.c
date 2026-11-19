#include <linux/bpf.h>

/* A scalar and a stack pointer share a register representation. The tag
 * distinguishes the paths; the verifier can retain that correlation. */
__attribute__((section("xdp"), used))
int guarded_difference(struct xdp_md *ctx)
{
    char arena[16];
    void *volatile saved;
    volatile unsigned long saved_tag;
    if (ctx->rx_queue_index & 1) {
        saved = &arena[8];
        saved_tag = 4;
    } else {
        saved = (void *)(unsigned long)ctx->ingress_ifindex;
        saved_tag = 0;
    }
    void *value = saved;
    unsigned long tag = saved_tag;
    asm volatile("" : "+r"(value));
    unsigned long native_base = ctx->ingress_ifindex;
    unsigned long result = (unsigned long)value;
    if (tag == 4) {
        unsigned long delta = (unsigned long)value - (unsigned long)&arena[0] - sizeof(arena);
        asm volatile("" : "+r"(delta));
        result = delta + native_base;
    }
    return result;
}

char fixture_license[] __attribute__((section("license"), used)) = "GPL";
