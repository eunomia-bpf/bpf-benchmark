#include <linux/bpf.h>

/* A scalar and a stack pointer share a register representation. The tag
 * distinguishes the paths; the verifier can retain that correlation. */
__attribute__((section("xdp"), used))
int guarded_difference(struct xdp_md *ctx)
{
    char arena[16];
    void *volatile saved;
    volatile unsigned char saved_tag;
    if (ctx->rx_queue_index & 1) {
        saved = &arena[8];
        saved_tag = 4;
    } else {
        saved = (void *)(unsigned long)ctx->ingress_ifindex;
        saved_tag = 0;
    }
    void *value = saved;
    unsigned char tag = saved_tag;
    asm volatile("" : "+r"(value));
    if (tag == 4) {
        unsigned long delta = (unsigned long)value - (unsigned long)&arena[16];
        asm volatile("" : "+r"(delta));
        return delta == (unsigned long)-8 ? XDP_PASS : XDP_DROP;
    }
    return XDP_DROP;
}

char fixture_license[] __attribute__((section("license"), used)) = "GPL";
