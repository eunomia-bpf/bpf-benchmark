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
int test_zero_applied_noop_select(struct xdp_md *ctx)
{
	void *data = (void *)(long)ctx->data;
	void *data_end = (void *)(long)ctx->data_end;
	volatile __u8 *p = data;
	register __u64 cond_a asm("r2");
	register __u64 cond_b asm("r3");
	register __u64 x asm("r6");
	__u32 key = 0;
	__u64 *slot;

	if (data + 2 > data_end)
		return XDP_ABORTED;

	cond_a = p[0];
	cond_b = p[1];
	x = ((__u64)cond_a << 8) | cond_b;
	asm volatile(
		"%[x] = %[x]\n\t"
		"if %[cond_a] > %[cond_b] goto +1\n\t"
		"%[x] = %[x]\n\t"
		: [x] "+r"(x)
		: [cond_a] "r"(cond_a),
		  [cond_b] "r"(cond_b));

	slot = bpf_map_lookup_elem(&result_map, &key);
	if (slot)
		*slot = x;

	return XDP_PASS;
}

char _license[] SEC("license") = "GPL";
