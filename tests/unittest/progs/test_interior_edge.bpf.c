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
int test_interior_edge(struct xdp_md *ctx)
{
	void *data = (void *)(long)ctx->data;
	void *data_end = (void *)(long)ctx->data_end;
	volatile __u8 *p = data;
	register __u64 gate asm("r5");
	register __u64 cond_a asm("r2");
	register __u64 cond_b asm("r3");
	register __u64 true_v asm("r7");
	register __u64 false_v asm("r8");
	register __u64 x asm("r6");
	__u32 key = 0;
	__u64 *slot;

	if (data + 5 > data_end)
		return XDP_ABORTED;

	gate = p[4];
	cond_a = p[0];
	cond_b = p[1];
	true_v = p[2];
	false_v = p[3];
	asm volatile(
		"%[x] = %[true_v]\n\t"
		"if %[gate] & 1 goto +1\n\t"
		"%[x] = %[true_v]\n\t"
		"if %[cond_a] > %[cond_b] goto +1\n\t"
		"%[x] = %[false_v]\n\t"
		: [x] "=&r"(x)
		: [gate] "r"(gate),
		  [cond_a] "r"(cond_a),
		  [cond_b] "r"(cond_b),
		  [true_v] "r"(true_v),
		  [false_v] "r"(false_v));

	slot = bpf_map_lookup_elem(&result_map, &key);
	if (slot)
		*slot = x;

	return XDP_PASS;
}

char _license[] SEC("license") = "GPL";
