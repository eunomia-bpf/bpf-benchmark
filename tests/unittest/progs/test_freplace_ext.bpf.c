// SPDX-License-Identifier: GPL-2.0
/*
 * Freplace extension program -- replaces get_result() in the target program.
 * Returns 0 instead of the original 42.
 */
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

SEC("freplace/get_result")
int new_get_result(void)
{
	return 0;
}

char LICENSE[] SEC("license") = "GPL";
