/*
 * Stage 2 test: HASH map with a 16-byte string key.
 *
 * Real-world shape: per-process / per-cgroup / per-command lookup
 * keyed by a fixed-length name buffer (tetragon / bpftrace pattern).
 * Larger key means the inline `add rax, KEY_OFFSET` after
 * `__htab_map_lookup_elem` carries a larger immediate than the u32-key
 * case -- still well within imm8 range here.
 *
 * Maps: 1 (HASH).   Helpers: 0.   Inline-eligible: yes.
 */
#include "include/native_helpers.h"

/* 16-byte key declared as 2 u64s so clang materializes the literal as
 * two `mov qword [rsp+N], imm64` stack stores instead of `memcpy` from
 * a `.rodata` symbol (the latter would emit an R_X86_64_PC32 reloc that
 * native-link doesn't yet handle for embedded rodata). The map key
 * type is the same 16 contiguous bytes either way. */
struct key16 { __u64 lo; __u64 hi; };

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 8);
    __type(key, struct key16);
    __type(value, __u64);
} str_hash SEC(".maps");

SEC("xdp") int map_hash_str_key(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    if (data + 8 > data_end) {
        return XDP_ABORTED;
    }

    /* "bpf-bench-key-00" in little-endian */
    struct key16 k = { 0x636e65622d667062ULL, 0x30302d79656b2d68ULL };
    __u64 v = 0xFEEDFACEDEADBEEFULL;
    bpf_map_update_elem(&str_hash, &k, &v, 0);

    __u64 *got = bpf_map_lookup_elem(&str_hash, &k);
    __u64 out = got ? *got : 0;
    micro_write_u64_le(data, out);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
