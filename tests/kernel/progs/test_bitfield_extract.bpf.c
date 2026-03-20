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
int test_bitfield_extract(struct xdp_md *ctx)
{
	__u64 word = ((__u64)ctx->ingress_ifindex << 32) | ctx->rx_queue_index;
	__u64 field;
	__u32 key = 0;
	__u64 *slot;

	field = word;
	field >>= 5;
	field &= 0x1f;
	field += 0x1234;

	slot = bpf_map_lookup_elem(&result_map, &key);
	if (slot)
		*slot = field;

	return XDP_PASS;
}

char _license[] SEC("license") = "GPL";
