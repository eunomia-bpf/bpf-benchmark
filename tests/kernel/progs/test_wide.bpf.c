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
int test_wide(struct xdp_md *ctx)
{
	void *data = (void *)(long)ctx->data;
	void *data_end = (void *)(long)ctx->data_end;
	volatile __u8 *p = data + 1;
	register __u64 v asm("r6");
	__u64 lo;
	__u32 key = 0;
	__u64 *slot;

	if (data + 3 > data_end)
		return XDP_ABORTED;

	v = p[1];
	v <<= 8;
	asm volatile("" : "+r"(v));
	lo = p[0];
	v |= lo;

	if (v == 0xdead)
		return XDP_DROP;

	slot = bpf_map_lookup_elem(&result_map, &key);
	if (slot)
		*slot = v;

	return XDP_PASS;
}

char _license[] SEC("license") = "GPL";
