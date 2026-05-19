/*
 * Stage 2 test: 3-map chain (ARRAY -> HASH -> PERCPU_ARRAY).
 *
 * Real-world shape: cilium-style policy chain --
 *   index by something packet-derived into a POLICY ARRAY,
 *   take that policy id and look up metadata in a HASH table,
 *   then bump a per-cpu counter so userspace can read rates.
 *
 * Crucially, this is a multi-map program: native-link MUST NOT inline
 * `bpf_map_lookup_elem` here, because two of the three lookups go to
 * non-HASH maps and would be misrouted to `__htab_map_lookup_elem`.
 * The runner enforces that (single-HASH-only inline) so this test
 * verifies the correctness guard works.
 *
 * Maps: 3 (ARRAY + HASH + PERCPU_ARRAY).
 * Helpers: 0 (besides map ops).
 * Inline-eligible: no (multi-map; runner refuses to set
 *                  --inline-hash-lookup when other map types coexist).
 */
#include "include/native_helpers.h"

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 16);
    __type(key, __u32);
    __type(value, __u64);
} policy_array SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 64);
    __type(key, __u64);
    __type(value, __u64);
} meta_hash SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_PERCPU_ARRAY);
    __uint(max_entries, 8);
    __type(key, __u32);
    __type(value, __u64);
} counter_pcpu SEC(".maps");

SEC("xdp") int multi_map_policy(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 8 > data_end) {
        return XDP_ABORTED;
    }

    /* Initialize all three maps with known values so the result is
     * deterministic. */
    __u32 policy_idx = 3;
    __u64 policy_id  = 0xAABBCCDDEEFF0011ULL;
    bpf_map_update_elem(&policy_array, &policy_idx, &policy_id, 0);

    __u64 meta_val = 0x1234567812345678ULL;
    bpf_map_update_elem(&meta_hash, &policy_id, &meta_val, 0);

    __u32 cz = 0;
    __u64 zero = 0;
    bpf_map_update_elem(&counter_pcpu, &cz, &zero, 0);

    /* Chain lookups. */
    __u64 *pol = bpf_map_lookup_elem(&policy_array, &policy_idx);
    __u64 *meta = 0;
    if (pol) {
        meta = bpf_map_lookup_elem(&meta_hash, pol);
    }
    __u64 *cnt = bpf_map_lookup_elem(&counter_pcpu, &cz);
    if (cnt && meta) {
        *cnt = *meta;
    }
    __u64 out = cnt ? *cnt : 0;
    micro_write_u64_le(data, out);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
