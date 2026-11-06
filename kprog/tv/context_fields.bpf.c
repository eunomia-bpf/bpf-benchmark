#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

/* One virtual field per entry makes the kernel's exact conversion extent
 * observable independently of instruction scheduling and register allocation.
 */
#define FIELD(name) \
    SEC("xdp") int tv_ctx_##name(struct xdp_md *ctx) { \
        unsigned long value = ctx->name; \
        asm volatile("" : : "r"(value)); \
        return 0; \
    }
FIELD(data)
FIELD(data_end)
FIELD(data_meta)
FIELD(ingress_ifindex)
FIELD(rx_queue_index)
FIELD(egress_ifindex)
char LICENSE[] SEC("license") = "GPL";
