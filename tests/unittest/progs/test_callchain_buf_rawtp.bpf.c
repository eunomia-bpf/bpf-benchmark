// SPDX-License-Identifier: GPL-2.0

#include <linux/bpf.h>

typedef __u32 __wsum;

#include "bpf_helpers.h"

struct callchain_state_value {
	__u64 hits;
	__s32 last_stack_size;
	__u32 pad;
};

struct {
	__uint(type, BPF_MAP_TYPE_ARRAY);
	__uint(max_entries, 1);
	__type(key, __u32);
	__type(value, struct callchain_state_value);
} state_map SEC(".maps");

struct {
	__uint(type, BPF_MAP_TYPE_PERCPU_ARRAY);
	__uint(max_entries, 1);
	__type(key, __u32);
	__type(value, __u64[64]);
} scratch_map SEC(".maps");

SEC("raw_tracepoint/sys_enter")
int test_callchain_buf_rawtp(void *ctx)
{
	struct callchain_state_value *state;
	__u64 *scratch;
	__u32 key = 0;
	long stack_size;

	state = bpf_map_lookup_elem(&state_map, &key);
	scratch = bpf_map_lookup_elem(&scratch_map, &key);
	if (!state || !scratch)
		return 0;

	stack_size = bpf_get_stack(ctx, scratch, sizeof(__u64) * 64, 0);
	state->last_stack_size = stack_size;
	if (stack_size > 0)
		__sync_fetch_and_add(&state->hits, 1);

	return 0;
}

char _license[] SEC("license") = "GPL";
