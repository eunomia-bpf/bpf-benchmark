// SPDX-License-Identifier: GPL-2.0
/*
 * Minimal struct_ops program implementing tcp_congestion_ops.
 * Only the .init callback and .name are filled in; all other callbacks
 * are left NULL (kernel uses defaults for missing callbacks).
 */
#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>

char LICENSE[] SEC("license") = "GPL";

SEC("struct_ops")
void BPF_PROG(test_init, struct sock *sk)
{
}

SEC("struct_ops")
__u32 BPF_PROG(test_ssthresh, struct sock *sk)
{
	return 0x7fffffff;
}

SEC("struct_ops")
void BPF_PROG(test_cong_avoid, struct sock *sk, __u32 ack, __u32 acked)
{
}

SEC("struct_ops")
__u32 BPF_PROG(test_undo_cwnd, struct sock *sk)
{
	return ((struct tcp_sock *)sk)->snd_cwnd;
}

SEC(".struct_ops")
struct tcp_congestion_ops test_tcp_ops = {
	.init		= (void *)test_init,
	.ssthresh	= (void *)test_ssthresh,
	.cong_avoid	= (void *)test_cong_avoid,
	.undo_cwnd	= (void *)test_undo_cwnd,
	.name		= "bpf_rejit_test",
};
