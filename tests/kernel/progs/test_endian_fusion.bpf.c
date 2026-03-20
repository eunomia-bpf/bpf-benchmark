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
int test_endian_fusion(struct xdp_md *ctx)
{
	register __u64 value asm("r6");
	__u32 key = 0;
	__u64 *slot;

	slot = bpf_map_lookup_elem(&result_map, &key);
	if (slot) {
		asm volatile(
			"%[value] = *(u32 *)(%[ctx] + %[off])\n\t"
			"%[value] = be32 %[value]\n\t"
			: [value] "=&r"(value)
			: [ctx] "r"(ctx),
			  [off] "i"(__builtin_offsetof(struct xdp_md,
						       ingress_ifindex)));

		value += ((__u64)ctx->rx_queue_index << 32) | 0xaa55;
		*slot = value;
	}

	return XDP_PASS;
}

char _license[] SEC("license") = "GPL";
