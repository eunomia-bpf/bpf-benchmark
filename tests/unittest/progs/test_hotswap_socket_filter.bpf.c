// SPDX-License-Identifier: GPL-2.0

#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

SEC("socket")
int rejit_hotswap_socket_filter(struct __sk_buff *skb)
{
	return 0xffff;
}

char LICENSE[] SEC("license") = "GPL";
