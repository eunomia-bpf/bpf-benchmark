/* Same test source for stock BPF and native P. No production application edits. */
#include <linux/types.h>
#ifdef __BPF__
static long (*bpf_probe_read_user)(void *, __u32, const void *) = (void *)112;
static long (*bpf_probe_read_kernel)(void *, __u32, const void *) = (void *)113;
#else
extern long bpf_probe_read_user(void *, __u32, const void *);
extern long bpf_probe_read_kernel(void *, __u32, const void *);
#endif
__attribute__((section("raw_tp/sys_enter"),used))
int entry(const unsigned long *ctx)
{
    unsigned char result[16];
    const unsigned long local[2] = {0x0807060504030201UL,0x100f0e0d0c0b0a09UL};
    const void *source = ctx[1] == 2 ? local : (const void *)ctx[0];
    long error = ctx[1] ? bpf_probe_read_kernel(result,16,source) : bpf_probe_read_user(result,16,source);
    unsigned sum = 0;
#pragma unroll
    for (unsigned i=0;i<16;++i) sum += result[i];
    return (sum<<8) | (error & 255);
}
char LICENSE[] __attribute__((section("license"),used)) = "GPL";
