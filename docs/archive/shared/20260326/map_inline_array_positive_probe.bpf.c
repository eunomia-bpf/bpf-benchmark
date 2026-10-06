// SPDX-License-Identifier: GPL-2.0

#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

struct probe_value {
	__u64 a;
	__u64 b;
};

struct {
	__uint(type, BPF_MAP_TYPE_ARRAY);
	__uint(max_entries, 1);
	__type(key, __u32);
	__type(value, struct probe_value);
} cfg_map SEC(".maps");

SEC("xdp")
int map_inline_array_positive(struct xdp_md *ctx)
{
	__u32 key = 0;
	struct probe_value *cfg;
	__u64 sum;

	(void)ctx;

	cfg = bpf_map_lookup_elem(&cfg_map, &key);
	if (!cfg)
		return XDP_ABORTED;

	sum = cfg->a + cfg->b;
	if (sum == 0x123456789abcdef0ULL)
		return XDP_DROP;

	return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
