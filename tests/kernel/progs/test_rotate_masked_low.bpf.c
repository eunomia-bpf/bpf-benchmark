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
int test_rotate_masked_low(struct xdp_md *ctx)
{
	register __u64 x asm("r6");
	register __u64 tmp asm("r7");
	__u32 key = 0;
	__u64 *slot;

	x = ((__u64)ctx->rx_queue_index << 32) | ctx->ingress_ifindex;
	x += 0x01020304ULL;
	asm volatile(
		"%[tmp] = %[x]\n\t"
		"%[tmp] &= 16777215\n\t"
		"%[tmp] >>= 24\n\t"
		"%[x] <<= 8\n\t"
		"%[x] |= %[tmp]\n\t"
		: [x] "+r"(x), [tmp] "=&r"(tmp));

	slot = bpf_map_lookup_elem(&result_map, &key);
	if (slot)
		*slot = x;

	return XDP_PASS;
}

char _license[] SEC("license") = "GPL";
