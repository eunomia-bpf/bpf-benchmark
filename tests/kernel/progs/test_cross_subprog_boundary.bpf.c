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

static __noinline __u64 boundary_rotate(__u64 x, __u64 salt)
{
	x ^= salt;
	x += 0x0102030405060708ULL;
	x = (x << 8) | (x >> 56);

	return x;
}

static __noinline __u64 follow_leaf(__u64 x)
{
	x ^= 0x1111222233334444ULL;
	return x + 0x33;
}

SEC("xdp")
int test_cross_subprog_boundary(struct xdp_md *ctx)
{
	__u64 x = ((__u64)ctx->rx_queue_index << 32) | ctx->ingress_ifindex;
	__u64 salt = ((__u64)ctx->ingress_ifindex << 8) | 0x5a;
	__u32 key = 0;
	__u64 *slot;

	x += 9;
	x = boundary_rotate(x, salt);
	x = follow_leaf(x);

	slot = bpf_map_lookup_elem(&result_map, &key);
	if (slot)
		*slot = x;

	return XDP_PASS;
}

char _license[] SEC("license") = "GPL";
