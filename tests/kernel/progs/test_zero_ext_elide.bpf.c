// SPDX-License-Identifier: GPL-2.0

#include <linux/bpf.h>

typedef __u32 __wsum;

#include "bpf_helpers.h"

struct {
	__uint(type, BPF_MAP_TYPE_ARRAY);
	__uint(max_entries, 1);
	__type(key, __u32);
	__type(value, __u64);
} result_map SEC(".maps");

SEC("xdp")
int test_zero_ext_elide(struct xdp_md *ctx)
{
	register __u64 x asm("r6") = ctx->rx_queue_index;
	register __u64 y asm("r7") = ctx->ingress_ifindex;
	__u64 hi = ((__u64)ctx->ingress_ifindex << 32) | 0x55;
	__u32 key = 0;
	__u64 *slot;

	asm volatile(
		"w6 += w7\n\t"
		"r6 = r6\n\t"
		: "+r"(x)
		: "r"(y));
	x += hi;

	slot = bpf_map_lookup_elem(&result_map, &key);
	if (slot)
		*slot = x;

	return XDP_PASS;
}

char _license[] SEC("license") = "GPL";
