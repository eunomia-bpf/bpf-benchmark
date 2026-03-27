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

SEC("perf_event")
int rejit_hotswap_perf_event(void *ctx)
{
	__u32 key = 0;
	struct hotswap_stats *stats;

	stats = bpf_map_lookup_elem(&stats_map, &key);
	if (!stats)
		return 0;

	__sync_fetch_and_add(&stats->total, 1);
	__sync_fetch_and_add(&stats->events, 1);
	return 0;
}

char LICENSE[] SEC("license") = "GPL";
