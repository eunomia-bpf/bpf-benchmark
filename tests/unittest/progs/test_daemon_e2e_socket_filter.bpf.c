// SPDX-License-Identifier: GPL-2.0

#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

struct {
	__uint(type, BPF_MAP_TYPE_ARRAY);
	__uint(max_entries, 1);
	__type(key, __u32);
	__type(value, __u32);
} cfg_map SEC(".maps");

SEC("socket")
int rejit_daemon_e2e_socket_filter(struct __sk_buff *skb)
{
	__u32 key = 0;
	__u32 *cfg;

	cfg = bpf_map_lookup_elem(&cfg_map, &key);
	if (!cfg)
		return 0;

	return *cfg;
}

char LICENSE[] SEC("license") = "GPL";
