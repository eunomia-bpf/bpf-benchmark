/*
 * Standalone POC: uprobe attached to a function in the test harness
 * binary itself. The harness exposes `void uprobe_target(int)` as a
 * GLOBAL-EXPORT (non-static, non-inlined) symbol; the runner resolves
 * its file offset via objdump/readelf and attaches the program at that
 * offset against the harness's own executable path.
 *
 * Counts entries into a single-slot HASH map keyed by 0.
 */
#include "include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, __u64);
} count_map SEC(".maps");

SEC("uprobe")
int uprobe_handler(struct pt_regs *ctx)
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
