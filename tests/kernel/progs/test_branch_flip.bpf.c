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
int test_branch_flip(struct xdp_md *ctx)
{
	__u64 left = ctx->ingress_ifindex;
	__u64 right = ctx->rx_queue_index;
	__u64 acc = right + 0x1020;
	__u32 key = 0;
	__u64 *slot;

	if (left > right) {
		acc += 0x1357;
		acc ^= left;
	} else {
		acc ^= 0x2468;
		acc += right;
	}

	slot = bpf_map_lookup_elem(&result_map, &key);
	if (slot)
		*slot = acc;

	return XDP_PASS;
}

char _license[] SEC("license") = "GPL";
