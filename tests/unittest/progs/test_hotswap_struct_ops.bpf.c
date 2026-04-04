// SPDX-License-Identifier: GPL-2.0

#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>

#ifndef HOTSWAP_STRUCT_OPS_NAME
#define HOTSWAP_STRUCT_OPS_NAME "rjhtswp"
#endif

struct {
	__uint(type, BPF_MAP_TYPE_ARRAY);
	__uint(max_entries, 1);
	__type(key, __u32);
	__type(value, __u64);
} value_map SEC(".maps");

SEC("struct_ops")
void BPF_PROG(rejit_hotswap_struct_ops_init, struct sock *sk)
{
	__u32 key = 0;
	__u64 *value;

	value = bpf_map_lookup_elem(&value_map, &key);
	if (value)
		*value = 1111;
}

SEC("struct_ops")
__u32 BPF_PROG(rejit_hotswap_struct_ops_ssthresh, struct sock *sk)
{
	return 0x7fffffff;
}

SEC("struct_ops")
void BPF_PROG(rejit_hotswap_struct_ops_cong_avoid, struct sock *sk,
	      __u32 ack, __u32 acked)
{
}

SEC("struct_ops")
__u32 BPF_PROG(rejit_hotswap_struct_ops_undo_cwnd, struct sock *sk)
{
	return ((struct tcp_sock *)sk)->snd_cwnd;
}

SEC(".struct_ops")
struct tcp_congestion_ops rejit_hotswap_ca = {
	.init = (void *)rejit_hotswap_struct_ops_init,
	.ssthresh = (void *)rejit_hotswap_struct_ops_ssthresh,
	.cong_avoid = (void *)rejit_hotswap_struct_ops_cong_avoid,
	.undo_cwnd = (void *)rejit_hotswap_struct_ops_undo_cwnd,
	.name = HOTSWAP_STRUCT_OPS_NAME,
};

char LICENSE[] SEC("license") = "GPL";
