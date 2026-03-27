// SPDX-License-Identifier: GPL-2.0

#include "vmlinux.h"
#include "bpf_helpers.h"

SEC("cgroup_skb/egress")
int rejit_hotswap_cgroup_skb(struct __sk_buff *skb)
{
	return 1;
}

char LICENSE[] SEC("license") = "GPL";
