/*
 * Stage 2 test: ARRAY map indexed by a packet byte.
 *
 * Real-world shape: per-port stats / fixed-bucket histogram where the
 * bucket index comes from packet content. The BPF JIT inlines ARRAY
 * `bpf_map_lookup_elem` to a direct bounds-checked array read; native
 * code still issues a full `call bpf_map_lookup_elem` (no inline).
 *
 * To stay deterministic with the test_run input (zero-filled 64 B
 * packet), we read the index from byte 16 (outside the 0..7 result-
 * write zone) which is always 0, then populate slot 0 with a known
 * value before the lookup.
 *
 * Maps: 1 (ARRAY).   Helpers: 0.   Inline-eligible: no (not HASH).
 */
#include "include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 16);
    __type(key, __u32);
    __type(value, __u64);
} idx_array SEC(".maps");

SEC("xdp") int map_array_index_packet(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 32 > data_end) {
        return XDP_ABORTED;
    }

    __u32 init_key = 0;
    __u64 init_val = 0xDEADBEEFCAFEBABEULL;
    bpf_map_update_elem(&idx_array, &init_key, &init_val, 0);

    __u32 key = (__u32)data[16] & 0xF; /* zero-input => key=0 */
    __u64 *got = bpf_map_lookup_elem(&idx_array, &key);
    __u64 out = got ? *got : 0;
    micro_write_u64_le(data, out);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
