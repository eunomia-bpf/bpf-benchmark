/*
 * Stage 2 test: LRU_HASH per-key counter (lookup, write-back).
 *
 * Real-world shape: bounded per-key rate counter where the kernel
 * evicts cold entries automatically (cilium connection-tracking,
 * tetragon process-event throttling). The BPF JIT does NOT inline
 * LRU_HASH `bpf_map_lookup_elem` because LRU access touches an
 * `access_state` bit that the inlined sequence couldn't update; native
 * code matches that behavior (regular helper call, no inline).
 *
 * Also exercises `bpf_map_delete_elem` to reset state per iteration so
 * the inner-repeat loop produces a deterministic result.
 *
 * Maps: 1 (LRU_HASH).   Helpers: 0 (besides map ops).
 * Inline-eligible: no (LRU_HASH != HASH).
 */
#include "include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_LRU_HASH);
    __uint(max_entries, 1024);
    __type(key, __u32);
    __type(value, __u64);
} cnt_lru SEC(".maps");

SEC("xdp") int map_lru_hash_counter(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 8 > data_end) {
        return XDP_ABORTED;
    }

    __u32 key = 42;
    bpf_map_delete_elem(&cnt_lru, &key);
    __u64 zero = 0;
    bpf_map_update_elem(&cnt_lru, &key, &zero, 0);

    __u64 *got = bpf_map_lookup_elem(&cnt_lru, &key);
    __u64 out = 0;
    if (got) {
        *got += 1;
        out = *got;
    }
    micro_write_u64_le(data, out);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
