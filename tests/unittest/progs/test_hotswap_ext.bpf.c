// SPDX-License-Identifier: GPL-2.0

#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

SEC("freplace/rejit_hotswap_ext_target_func")
int rejit_hotswap_ext(struct __sk_buff *skb)
{
	return 1111;
}

char LICENSE[] SEC("license") = "GPL";
