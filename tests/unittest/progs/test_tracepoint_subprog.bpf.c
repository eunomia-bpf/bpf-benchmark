// SPDX-License-Identifier: GPL-2.0

#include "vmlinux.h"
#include "bpf_helpers.h"

struct {
	__uint(type, BPF_MAP_TYPE_ARRAY);
	__uint(max_entries, 1);
	__type(key, __u32);
	__type(value, __u64);
} result_map SEC(".maps");

static __noinline __u64 mix_subprog(__u64 pid_tgid)
{
	pid_tgid ^= 0x0123456789abcdefULL;
	pid_tgid += 0x55aa55aa55aa55aaULL;
	return pid_tgid;
}

SEC("tracepoint/syscalls/sys_enter_execve")
int test_tracepoint_subprog(void *ctx)
{
	__u32 key = 0;
	__u64 *slot;
	__u64 value;

	value = mix_subprog(bpf_get_current_pid_tgid());
	slot = bpf_map_lookup_elem(&result_map, &key);
	if (slot)
		*slot = value;

	return 0;
}

char LICENSE[] SEC("license") = "GPL";
