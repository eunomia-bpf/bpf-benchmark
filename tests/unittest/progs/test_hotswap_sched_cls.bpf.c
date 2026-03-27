// SPDX-License-Identifier: GPL-2.0

#include "vmlinux.h"
#include "bpf_helpers.h"

#define TC_ACT_OK 0

SEC("tc")
int rejit_hotswap_sched_cls(struct __sk_buff *skb)
{
	return TC_ACT_OK;
}

char LICENSE[] SEC("license") = "GPL";
