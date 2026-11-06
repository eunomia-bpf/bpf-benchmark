#include <linux/bpf.h>
#include <bpf_helpers.h>
SEC("xdp") int runtime_source(struct xdp_md *ctx)
{
    (void)ctx;
    return 127;
}
char LICENSE[] SEC("license") = "GPL";
