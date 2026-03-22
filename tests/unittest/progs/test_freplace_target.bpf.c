// SPDX-License-Identifier: GPL-2.0
/*
 * Freplace target program -- a simple sched_cls program with a global
 * (non-static, __noinline) function that can be replaced via BPF_PROG_TYPE_EXT.
 *
 * The global function get_result() returns a constant value.  The freplace
 * extension program will provide a different implementation.
 */
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

__noinline int get_result(void)
{
	return 42;
}

SEC("tc")
int test_freplace_target(struct __sk_buff *skb)
{
	return get_result();
}

char LICENSE[] SEC("license") = "GPL";
