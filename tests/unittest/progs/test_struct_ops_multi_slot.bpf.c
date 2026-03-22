// SPDX-License-Identifier: GPL-2.0
/*
 * Struct_ops program for H3 multi-slot REJIT regression test.
 *
 * Four callbacks are filled in tcp_congestion_ops.  The test REJIT's
 * a specific callback (e.g., ms_undo_cwnd at slot index 8) and
 * verifies that the refresh_prog loop correctly iterates past
 * non-matching earlier slots (init at 12, cong_avoid at 0, ssthresh
 * at 2) to patch the right trampoline.
 *
 * Additionally, REJIT'ing ms_ssthresh and ms_undo_cwnd back-to-back
 * exercises the loop twice, verifying each trampoline is patched
 * independently.
 */
#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>

char LICENSE[] SEC("license") = "GPL";

SEC("struct_ops")
void BPF_PROG(ms_init, struct sock *sk)
{
}

SEC("struct_ops")
__u32 BPF_PROG(ms_ssthresh, struct sock *sk)
{
	return 0x7fffffff;
}

SEC("struct_ops")
void BPF_PROG(ms_cong_avoid, struct sock *sk, __u32 ack, __u32 acked)
{
}

SEC("struct_ops")
__u32 BPF_PROG(ms_undo_cwnd, struct sock *sk)
{
	return ((struct tcp_sock *)sk)->snd_cwnd;
}

SEC(".struct_ops")
struct tcp_congestion_ops multi_slot_ops = {
	.init		= (void *)ms_init,
	.ssthresh	= (void *)ms_ssthresh,
	.cong_avoid	= (void *)ms_cong_avoid,
	.undo_cwnd	= (void *)ms_undo_cwnd,
	.name		= "bpf_multi_slot",
};
