// SPDX-License-Identifier: GPL-2.0

#include <linux/bpf.h>

typedef __u32 __wsum;

#include "bpf_helpers.h"
#include "bpf_tracing.h"

struct {
	__uint(type, BPF_MAP_TYPE_ARRAY);
	__uint(max_entries, 1);
	__type(key, __u32);
	__type(value, __u64);
} result_map SEC(".maps");

SEC("fentry")
int BPF_PROG(test_simple_fentry)
{
	__u32 key = 0;
	__u64 *slot;

	slot = bpf_map_lookup_elem(&result_map, &key);
	if (slot)
		*slot += 1;

	return 0;
}

char _license[] SEC("license") = "GPL";
