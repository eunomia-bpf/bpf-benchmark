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

static __noinline __u64 rotate_leaf(__u64 x)
{
	x += 0x013579bd02468aceULL;
	x ^= 0x1111222233334444ULL;
	x = (x << 8) | (x >> 56);

	return x;
}

static __noinline __u64 mix_subprog(__u64 x)
{
	x ^= 0x0123456789abcdefULL;
	return rotate_leaf(x) + 0x55;
}

SEC("xdp")
int test_subprog_rotate(struct xdp_md *ctx)
{
	__u64 x = ((__u64)ctx->rx_queue_index << 32) | ctx->ingress_ifindex;
	__u32 key = 0;
	__u64 *slot;

	x += 7;
	x = mix_subprog(x);

	slot = bpf_map_lookup_elem(&result_map, &key);
	if (slot)
		*slot = x;

	return XDP_PASS;
}

char _license[] SEC("license") = "GPL";
