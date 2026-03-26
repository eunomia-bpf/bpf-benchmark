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
int test_addr_calc(struct xdp_md *ctx)
{
	register __u64 index asm("r6") = ctx->rx_queue_index;
	register __u64 base asm("r7") = ((__u64)ctx->ingress_ifindex << 4) | 3;
	register __u64 addr asm("r8");
	__u32 key = 0;
	__u64 *slot;

	asm volatile(
		"%[addr] = %[index]\n\t"
		"%[addr] <<= 3\n\t"
		"%[addr] += %[base]\n\t"
		: [addr] "=&r"(addr)
		: [index] "r"(index), [base] "r"(base));
	addr ^= index;
	addr ^= 0x55aa;

	slot = bpf_map_lookup_elem(&result_map, &key);
	if (slot)
		*slot = addr;

	return XDP_PASS;
}

char _license[] SEC("license") = "GPL";
