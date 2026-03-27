// SPDX-License-Identifier: GPL-2.0

#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

__noinline int rejit_hotswap_ext_target_func(struct __sk_buff *skb)
{
	return skb->len;
}

SEC("tc")
int rejit_hotswap_ext_target(struct __sk_buff *skb)
{
	return rejit_hotswap_ext_target_func(skb);
}

char LICENSE[] SEC("license") = "GPL";
