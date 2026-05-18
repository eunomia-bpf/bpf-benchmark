/*
 * Standalone POC: raw_tracepoint on sched_switch. Counts every
 * context-switch into a single-slot HASH map keyed by 0. The harness
 * triggers a known number of switches by sched_yield()ing in a tight
 * loop after attach.
 *
 * Using `raw_tracepoint` (not `tp/sched/sched_switch`) because:
 *   - raw_tp has a stable, well-documented ctx layout (`struct
 *     bpf_raw_tracepoint_args`) — no tracefs format file parsing.
 *   - The native_lab kinsn path doesn't yet wire up tp-ctx BTF
 *     relocations, so a CTX-agnostic program is the simplest case
 *     to start with.
 */
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, __u64);
} count_map SEC(".maps");

SEC("raw_tp/sched_switch")
int raw_tp_sched_switch(struct bpf_raw_tracepoint_args *ctx)
{
    __u32 key = 0;
    __u64 *val = bpf_map_lookup_elem(&count_map, &key);
    if (val) {
        __sync_fetch_and_add(val, 1);
    } else {
        __u64 init = 1;
        bpf_map_update_elem(&count_map, &key, &init, 0);
    }
    return 0;
}

char LICENSE[] SEC("license") = "GPL";
