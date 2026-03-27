// SPDX-License-Identifier: GPL-2.0

#include "vmlinux.h"
#include "bpf_helpers.h"

struct hotswap_stats {
	__u64 total;
	__u64 events;
};

struct {
	__uint(type, BPF_MAP_TYPE_ARRAY);
	__uint(max_entries, 1);
	__type(key, __u32);
	__type(value, struct hotswap_stats);
} stats_map SEC(".maps");

SEC("xdp")
int rejit_hotswap_xdp(struct xdp_md *ctx)
{
	__u32 key = 0;
	struct hotswap_stats *stats;

	stats = bpf_map_lookup_elem(&stats_map, &key);
	if (!stats)
		return XDP_PASS;

	__sync_fetch_and_add(&stats->total, 1);
	__sync_fetch_and_add(&stats->events, 1);
	return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
