// SPDX-License-Identifier: GPL-2.0
/*
 * Freplace target program -- a simple sched_cls program with a global
 * (non-static, __noinline) function that can be replaced via BPF_PROG_TYPE_EXT.
 *
 * The global function get_result() returns a value derived from its argument.
 * The freplace extension program will provide a different implementation.
 *
 * We use volatile + asm("" : "+r" ...) to prevent constant folding and ensure
 * the function is a real BPF-to-BPF subprogram call.
 */
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

__noinline int get_result(struct __sk_buff *skb)
{
	return skb->len;
}

SEC("tc")
int test_freplace_target(struct __sk_buff *skb)
{
	return get_result(skb);
}

char LICENSE[] SEC("license") = "GPL";
