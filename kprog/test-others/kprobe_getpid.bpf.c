/*
 * Standalone POC: kprobe on the getpid syscall entry. Counts entries
 * into a single-slot HASH map keyed by 0. Triggered by the test
 * harness calling getpid() in a tight loop after attach.
 *
 * Native_lab note: this program type is `kprobe`. To run it via the
 * native_lab kop path, the standalone runner would have to load the
 * stub `(sidecar; call kop)*N; exit` program with
 * prog_type=BPF_PROG_TYPE_KPROBE and attach it via
 * perf_event_open(PERF_TYPE_TRACEPOINT, kprobe ID) + PERF_EVENT_IOC_SET_BPF.
 * The existing `micro_exec run-native-lab` runner only wires up the
 * BPF_PROG_TEST_RUN path (xdp/sched_cls/cgroup_skb); kprobe support
 * requires a separate attach pipeline, exercised here for the first
 * time.
 */
#include "include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, __u64);
} count_map SEC(".maps");

SEC("kprobe/__x64_sys_getpid")
int kprobe_getpid(struct pt_regs *ctx)
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
