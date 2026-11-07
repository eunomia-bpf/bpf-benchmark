#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
SEC("xdp") int dump_control(struct xdp_md *ctx) { return XDP_PASS; }
char LICENSE[] SEC("license")="GPL";
